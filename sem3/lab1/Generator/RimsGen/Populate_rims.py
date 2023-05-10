import random
import sys
from faker import Faker

if __name__ == '__main__':
    fake = Faker()
    step = 100
    brands = ['BBS','Vossen','Z','OZ','Venom']
    header = "insert into primu_rims(\"rimBrand\", \"rimModel\", height, width, \"carModel_id\") VALUES"
    file_prefix = "rims_"
    file_suffix = ".sql"

    original_stdout = sys.stdout


    for i in range(1):
        with open(f"{file_prefix}{i}{file_suffix}", "w") as file:
            sys.stdout = file
            print(header)
            for j in range(step):
                print(
                    f"('{random.choice(brands)}','{fake.word()}',{random.randint(14,28)},{random.randint(100,300)},{random.randint(1,50)})",
                    end='')

                if j != step - 1:
                    print(',')

        sys.stdout = original_stdout
        print(f"{i+1}/1000")