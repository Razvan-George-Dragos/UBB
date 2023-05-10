import { Car } from "./Cars";

export interface Rim{
    id: number;
    rimBrand: string;
    rimModel: string;
    height: number;
    width: number;
    carModel: Car;
}