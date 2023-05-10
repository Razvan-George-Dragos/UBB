import random
import sys
from faker import Faker

if __name__ == '__main__':
    fake = Faker()
    step = 1000
    brands = ['BMW', 'Audi', 'Mercedes', 'Porsche', 'Bugatti', 'Ferrari', 'Dacia', 'Renault', 'Toyota', 'Lamborghini', 'Maseratti', 'Aixam', 'Jaguar', 'Seat', 'VolksWagen', 'Skoda', 'Peugeot']
    header = "insert into primu_car(brand, mod, \"chasisNr\", hp, \"yearOfRegistration\") VALUES "
    file_prefix = "car_"
    file_suffix = ".sql"

    original_stdout = sys.stdout


    for i in range(1):
        with open(f"{file_prefix}{i}{file_suffix}", "w") as file:
            sys.stdout = file
            print(header)
            for j in range(step):
                print(
                    f"('{random.choice(brands)}','{fake.word()}','{random.randint(1,1000000000)}',{random.randint(20,2000)},{random.randint(1900,2023)})",
                    end='')

                if j != step - 1:
                    print(',')

        sys.stdout = original_stdout
        print(f"{i+1}/1000")