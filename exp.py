import subprocess

wordlist_file = "wordlist.txt"

# Open the file as f.
# The function readlines() reads the file.
with open(wordlist_file) as f:
    content = f.readlines()
    wordlist = [word.strip('\n') for word in content]
    for payload in wordlist:
    	print('Trying password :',payload)
    	process = subprocess.Popen('./gro',stdout=subprocess.PIPE,stdin=subprocess.PIPE)
    	input_val = '1\n2\n{}'.format(payload)
    	#print(input_val)
    	output = process.communicate(input=input_val)[0]
    	#print(output)
    	all_msg = output.split('\n')
    	#print(all_msg)
    	if(all_msg[-3] != 'Wrong Password '):
			print("Login Successful , password is {}".format(payload))
			break