import os, subprocess

SUFFIX_IN = '.inp'
SUFFIX_OUT = '.out'
FOLDER = 'Data'
THRESHOLD = 24000000 #Bytes

os.chdir(FOLDER)


def zip(file_list, index):
    cmd = ['7z', 'a', '-tzip', FOLDER + str(index) + '.zip']
    cmd += file_list
    subprocess.call(cmd)


if __name__ == '__main__':
    sum_size = 0
    file_list = []
    index = 1
    all_file = os.listdir('.')
    all_file.sort()

    for file in all_file:
        tail = os.path.splitext(file)[1]
        if (tail in [SUFFIX_OUT, SUFFIX_IN]):
            sum_size += os.stat(file).st_size

            if (sum_size > THRESHOLD):
                zip(file_list, index)
                index += 1
                file_list = [file]
                sum_size = os.stat(file).st_size
            else:
                file_list.append(file)
    # zip last one
    if (len(file_list)):
        zip(file_list, index)

