import {
    Button,
    Card,
    CardActions,
    CardContent,
    CircularProgress,
    Container,
    IconButton,
    TextField,
  } from "@mui/material";
import { useEffect, useState } from "react";
import { Link, useNavigate, useParams } from "react-router-dom";
import ArrowBackIcon from "@mui/icons-material/ArrowBack";
import axios from "axios";
import { Car } from "../../models/Cars";
import { DEV_BACKEND_API_URL } from "../../constants"

export const CarUpdate = () => {
    const navigate = useNavigate();
    const { carId } = useParams();
  
    const [loading, setLoading] = useState(true);
    const [car, setCar] = useState<Car | null>(null);
  
    useEffect(() => {
      const fetchCar = async () => {
        try {
          const response = await axios.get<Car>(
            `${DEV_BACKEND_API_URL}/cars/${carId}`
          );
          setCar(response.data);
        } catch (error) {
          console.log(error);
        } finally {
          setLoading(false);
        }
      };
      fetchCar();
    }, [carId]);
  
    const updateCar = async (event: { preventDefault: () => void }) => {
      event.preventDefault();
      try {
        await axios.put(`${DEV_BACKEND_API_URL}/cars/${carId}`, car);
        navigate(`/cars/`);
      } catch (error) {
        console.log(error);
      }
    };
  
  
    return (
      <Container>
        {loading && <CircularProgress />}
  
        {!loading && !car && <div>Car not found</div>}
  
        {!loading && car && (
          <Card>
            <CardContent>
              <IconButton
                component={Link}
                sx={{ mr: 3 }}
                to={`/owners/`}
              >
                <ArrowBackIcon />
              </IconButton>{" "}
              <form onSubmit={updateCar}>
                <TextField
                  value={car.brand}
                  id="brand"
                  label="Car brand"
                  variant="outlined"
                  fullWidth
                  sx={{ mb: 2 }}
                  onChange={(event) =>
                    setCar({ ...car, brand: event.target.value })
                  }
                />
                <TextField
                  value={car.mod}
                  id="mod"
                  label="Model"
                  variant="outlined"
                  fullWidth
                  sx={{ mb: 2 }}
                  onChange={(event) =>
                    setCar({ ...car, mod: event.target.value })
                  }
                />
  
                <TextField
                  value={car.chasisNr}
                  id="chasisNr"
                  label="Chasis nr"
                  variant="outlined"
                  fullWidth
                  sx={{ mb: 2 }}
                  onChange={(event) =>
                    setCar({ ...car, chasisNr: Number(event.target.value) })
                  }
                />
  
                <TextField
                  value={car.hp}
                  id="hp"
                  label="Horse Power"
                  variant="outlined"
                  fullWidth
                  sx={{ mb: 2 }}
                  onChange={(event) =>
                    setCar({ ...car, hp: Number(event.target.value) })
                  }
                />
                <TextField
                  value={car.yearOfRegistration}
                  id="yearOfRegistration"
                  label="Year of registration"
                  variant="outlined"
                  fullWidth
                  sx={{ mb: 2 }}
                  onChange={(event) =>
                    setCar({ ...car, yearOfRegistration: Number(event.target.value) })
                  }
                />
  
                <Button type="submit">Update Car</Button>
              </form>
            </CardContent>
            <CardActions></CardActions>
          </Card>
        )}
      </Container>
    );
  };