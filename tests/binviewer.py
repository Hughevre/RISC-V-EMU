with open("test.bin", "rb") as f:
    content = f.read().hex()

content = ''.join([content[x:x+2][::-1] for x in range(0, len(content),2)])
content = ''.join([content[x:x+8][::-1] for x in range(0, len(content),8)])
 

for i, b in enumerate(content):
    if not i % 8:
        print("{:06x}:".format(i), end=' ')
    print("{:04b}".format(int(b,16)), end=' ')
    if not (i+1) % 8:
        print("\t",content[i-7:i+1])

