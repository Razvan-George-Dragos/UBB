import random
import sys
from faker import Faker

if __name__ == '__main__':
    fake = Faker()
    step = 100
    brands = ['BBS','Vossen','Z','OZ','Venom']
    header = "insert into primu_ownerscars(price, \"kmWhenBought\", car_id, owner_id) VALUES"
    file_prefix = "ownerscars_"
    file_suffix = ".sql"

    original_stdout = sys.stdout


    for i in range(2):
        with open(f"{file_prefix}{i}{file_suffix}", "w") as file:
            sys.stdout = file
            print(header)
            for j in range(step):
                print(
                    f"({random.randint(1,10000000)},{random.randint(1,1000000)},{random.randint(1,100)},{random.randint(1,1000)})",
                    end='')

                if j != step - 1:
                    print(',')

        sys.stdout = original_stdout
        print(f"{i+1}/1000")