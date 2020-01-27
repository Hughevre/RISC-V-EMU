import sys
from itertools import zip_longest

def _load(file_name):
    with open(file_name, "rb") as f:
        content = f.read().hex()

    order = lambda lst, size: [lst[x:x+size][::-1] for x in range(0, len(lst),size)]

    content = ''.join(order(content, 2))
    content = order(content, 8)
    
    content = [c.rjust(8,"f") for c in content]

    return content

load = lambda files: [_load(f) for f in files]


DEFAULT1 = "../tests/t__first/file_data_in.bin"
DEFAULT2 = "../tests/t__first/file_data_out.bin"


if not len(sys.argv)-2:
    file_name = [sys.argv[1]]
else:
    file_name = [DEFAULT1, DEFAULT2] if not len(sys.argv)-1 else [sys.argv[1], sys.argv[2]]

content = load(file_name)
if len(content) == 1:
    content.append('')

for line, c1, c2  in zip_longest(range(max([len(c) for c in content])), *content, fillvalue='ffffffff'):
    if c1 != c2 or '' == content[1]:
        if "reg" in file_name[0]:
            line = "PC" if line == 32 else "x"+str(line)
            print("{:>3}".format(line), end=' ')
        else:
            print("{:06x}:".format(line*8), end=' ')
    
        for c in ((c1, c2) if '' != content[1] else (c1,)):
            buffer = ''
            for i in c:
                buffer += "{:04b} ".format(int(i,16))
            print("{:>40}".format(buffer), end='\t')

        print()