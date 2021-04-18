import subprocess

process = subprocess.Popen('./gro',stdout=subprocess.PIPE,stdin=subprocess.PIPE)

overflow = 'a'*17
input_val = '1\n2\n{}\n'.format(overflow)
print(input_val)
output = process.communicate(input=input_val)[0]
print(output)