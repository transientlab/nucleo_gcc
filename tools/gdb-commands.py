import argparse
parser = argparse.ArgumentParser()
parser.add_argument('start')
parser.add_argument('end')
args = parser.parse_args()


start = int(args.start, base=16)
end = int(args.end, base=16)

print('start\t:', args.start, start, '\nend\t:', args.end, end)

with open('gdb-remote', 'w+') as file:
    file.write('set logging file gdb-log\n')
    file.write('set logging overwrite on\n')
    file.write('set logging enabled on\n')
    file.write('target extended-remote 192.168.0.3:3333\n')
    
    # change to read from "register-print"
    for i in range(start,end, 16):
        file.write('x ' + hex(i) + '\n')

    file.write('quit\n')