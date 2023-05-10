import { Car } from "./Cars";
import { Owners } from "./Owners";

export interface OwnersCars{
    id: number;
    price: number,
    kmWhenBought: number;
    car: Car;
    owner: Owners;
      
}