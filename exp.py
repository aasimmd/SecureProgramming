import subprocess
process = subprocess.Popen(['grocery.exe'],stdout=subprocess.PIPE,stdin=subprocess.PIPE,shell=True,text=True)
print(process)
print(process.communicate(input='1 2 admin\nadmin')[0])