from mss import Searcher


def main():
    ser = Searcher()
    print('-------------------------------------------------')
    print('START TEST')
    print(ser)
    print('num_targets: ', ser.num_targets)
    ser.add_target('草甘膦')
    ser.extend_targets(['草甘膦', 1, [], '十四烷二烯乙酸酯'])
    print('num_targets: ', ser.num_targets)
    print('OK')


if __name__ == '__main__':
    main()
