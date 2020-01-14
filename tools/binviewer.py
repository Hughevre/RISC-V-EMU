import sys

DEFAULT = "../bin/file_reg_in.bin"

file_name = DEFAULT if not len(sys.argv)-1 else sys.argv[1]

with open(file_name, "rb") as f:
    content = f.read().hex()

content = ''.join([content[x:x+2][::-1] for x in range(0, len(content),2)])
content = ''.join([content[x:x+8][::-1] for x in range(0, len(content),8)])
buffer = ''
for i, b in enumerate(content):
    if not i % 8:
        print("{:06x}:".format(i), end=' ')

    buffer += "{:04b} ".format(int(b,16))
    # print("{:04b}".format(int(b,16)), end=' ')
    if not (i+1) % 8:
        print(buffer, end='')
        buffer = ''
        print("\t",content[i-7:i+1])
if buffer:
    print("{:>40}".format(buffer), end=' ')
    print("\t","{:0>8}".format(content[i - i % 8:]))

# Register generator
# with open("../bin/file_reg_in.bin", "wb") as f:
#     for _ in range(32 * 4):
#         f.write(b'\x00')