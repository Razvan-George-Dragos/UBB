import random
import sys
from faker import Faker

if __name__ == '__main__':
    fake = Faker()
    step = 2
    styles = ['offroad','drag','turns','mountain','long']
    surfaces = ['dirt', 'concrette', 'turf', 'asphalt']
    brands = ['LeMans','Nurburgring','Hungaroring','Monaco','Adancata','Botiz','Dakar','MorganPark','Circuit Italia','Olimpic Park']
    header = "insert into primu_racetracks(name, lenght, style, surface, \"recordHolder_id\") VALUES"
    file_prefix = "racetracks_"
    file_suffix = ".sql"

    original_stdout = sys.stdout


    for i in range(step):
        with open(f"{file_prefix}{i}{file_suffix}", "w") as file:
            sys.stdout = file
            print(header)
            for j in range(step):
                print(
                    f"('{random.choice(brands)}',{random.randint(1,500)},'{random.choice(styles)}','{random.choice(surfaces)}',{random.randint(1,999999)})",
                    end='')

                if j != step - 1:
                    print(',')

        sys.stdout = original_stdout
        print(f"{i+1}/1000")