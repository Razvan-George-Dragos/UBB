import random
import sys
from faker import Faker

if __name__ == '__main__':
    fake = Faker()
    step = 1000
    header = "insert into primu_owners(name, addres, cnp) VALUES"
    file_prefix = "owner_"
    file_suffix = ".sql"

    original_stdout = sys.stdout


    for i in range(10):
        with open(f"{file_prefix}{i}{file_suffix}", "w") as file:
            sys.stdout = file
            print(header)
            for j in range(step):
                print(
                    f"('{fake.name()}','{fake.street_address()}','{random.randint(10000000000,99999999999999)}')",
                    end='')

                if j != step - 1:
                    print(',')

        sys.stdout = original_stdout
        print(f"{i+1}/1000")