import subprocess


def extract_base_addresses():
    subprocess.run("./register_print", shell=True)

def extract_typedefs(file_path):
    with open(file_path, 'r') as file:
        typedefs = []
        name = ''
        lines = file.readlines()
        for i, line in enumerate(lines[1:595], 1):
            if line.startswith('typedef struct'):
                for j in lines[i:]:
                    if j.startswith('  __IO uint32_t'):
                        typedefs.append(j.split('  __IO uint32_t ')[1].split(';')[0].replace(' ',''))
                    if j.startswith('} '):
                        name = j.split('} ')[1].split(';')[0].strip()
                        break
    return typedefs
    
def extract_periph_define(file_path):
    with open(file_path, 'r') as file:
        lines = file.readlines()
        addresses = []
        for k in lines[685:738]:
            str1 = 'printf("0x%" PRIXPTR "\\n", (uintptr_t)'
            str2 = ');'
            try:
                addresses.append(k.split(' *) ')[1].replace(')','').strip())
            except IndexError:
                assert True
    return addresses
                
if __name__ == '__main__':
    # extract_base_addresses()
    # print(extract_typedefs('/device/stm32f303x8.h'))
    print(extract_periph_define('/device/stm32f303x8.h'))