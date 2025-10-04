
# def prime_check(n):
#     check='true'
#     for a in range(n):
#         if (a!=1) and (a!=n) and (a!=0):
#             if n%a==0:
#                 check='false'
#     if check=='true':
#         print("Prime Number---")
#     else:
#         print("Not a prime number---")
# a=int(input("Enter any number??"))
# prime_check(a)


# Encryption and Decryption

# alphabet = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']


# def encode(text, shift):
#     alphabet = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']
#     encoded_text = ''
#     for i in text:
#         for position in range(len(alphabet)):
#             if i == alphabet[position]:
#                 new_ch = alphabet[(position + shift) % len(alphabet)]
#                 encoded_text += new_ch
#     print(encoded_text)

# def decode(text, shift):
#     alphabet = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']
#     decoded_text = ''
#     for i in text:
#         for position in range(len(alphabet)):
#             if i == alphabet[position]:
#                 new_ch = alphabet[(position - shift)]
#                 decoded_text += new_ch
#     print(decoded_text)
# direction = input("Type 'encode' to encrypt, type 'decode' to decrypt:\n")
# text = input("Type your message:\n").lower()
# shift = int(input("Type the shift number:\n"))

# if(direction=='encode'):
#     encode(text,shift)
# elif(direction=='decode'):
#     decode(text,shift)

# direction = input("Type 'encode' to encrypt, type 'decode' to decrypt:\n")
# text = input("Type your message:\n").lower()
# shift = int(input("Type the shift number:\n"))
# if(direction=='encode'):
#     encode(text,shift)
# elif(direction=='decode'):
#     decode(text,shift)

# ceaser function

def ceaser(text, shift, direction):
     alphabet = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']
     ceaser_text = ''
     for i in text:
        for position in range(len(alphabet)):
            if i == alphabet[position]:
                if direction=='encode':
                    new_ch = alphabet[(position + shift) % len(alphabet)]
                    ceaser_text += new_ch
                elif direction=='decode':
                    new_ch = alphabet[(position - shift) % len(alphabet)]
                    ceaser_text += new_ch
        if i==' ':
            new_ch=' '
            ceaser_text+=new_ch
     print(f"The {direction}d text is : {ceaser_text}.")

check='yes'
while check=='yes':
    direction = input("Type 'encode' to encrypt, type 'decode' to decrypt:\n").lower()
    text = input("Type your message:\n").lower()
    shift = int(input("Type the shift number:\n"))
    ceaser(text,shift,direction)
    check=input("If you to encode or decode more!! enter 'yes' or 'no' ").lower()
    
print("Good____BYeeeee")