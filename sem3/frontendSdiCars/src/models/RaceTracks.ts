import { Car } from "./Cars";

export interface RaceTrack{
    id: number;
    name: string;
    lenght: number;
    style: string;
    surface: string;
    recordHolder: Car;
}