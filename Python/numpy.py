
%%time
x=np.loadtxt('dataset.txt',dtype='str')
import numpy as np
valid_letters='abcdefghijklmnopqrstuvwxyz'
user_key='keyword'
key=''

cipher=[]
for char in user_key:
    if char in valid_letters:
            key+=char
for char in valid_letters:
    if char not in key:
        key+=char
        
def encrypt(clear_text):
    new_string=''
    for char in clear_text:
        if char in valid_letters:
            new_string+=char
    index_values=[valid_letters.index(char) for char in new_string]
    return "".join(key[indexkey] for indexkey in index_values)
for word in np.nditer(x):
    encrypt(str(word))