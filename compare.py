from random import randint
import os

CPP_FILE_NAME = 'hdu1232.cpp'


def gen():
    t = 100
    for _ in range(t):
        n = randint(2, 100)
        with open('in.txt', 'w+') as f:
            f.write(f"{n}\n")
            arr = [str(randint(130, 230)) for _ in range(n)]
            f.write(' '.join(arr))


def run():
    target = CPP_FILE_NAME.replace('.cpp', '')
    while True:
        gen()
        print('.', end='', flush=True)
        cmd1 = f"cmake-build-debug/{target} < in.txt"
        cmd2 = 'cmake-build-debug/answer < in.txt'
        ret1 = os.popen(cmd1).read()
        ret2 = os.popen(cmd2).read()
        if ret1 != ret2:
            with open('out1.txt', 'w') as f:
                f.write(ret1)
            with open('out2.txt', 'w') as f:
                f.write(ret2)
            break


if __name__ == '__main__':
    run()
