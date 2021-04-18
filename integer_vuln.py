import subprocess

process = subprocess.Popen('./gro',stdout=subprocess.PIPE,stdin=subprocess.PIPE)

input_val = '1\n1\nhi\nhi123\n4\n{}'.format(pow(2,25)-1) 
print(input_val)
output = process.communicate(input=input_val)[0]
print(output)