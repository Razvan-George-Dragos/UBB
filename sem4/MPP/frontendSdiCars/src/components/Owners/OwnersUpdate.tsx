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
import { Owners } from "../../models/Owners";
import { DEV_BACKEND_API_URL } from "../../constants"

export const OwnerUpdate = () => {
    const navigate = useNavigate();
    const { carId } = useParams();
  
    const [loading, setLoading] = useState(true);
    const [car, setCar] = useState<Owners | null>(null);
  
    useEffect(() => {
      const fetchCar = async () => {
        try {
          const response = await axios.get<Owners>(
            `${DEV_BACKEND_API_URL}/owners/${carId}`
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
        await axios.put(`${DEV_BACKEND_API_URL}/owners/?id=${carId}`, car);
        navigate(`/owners/`);
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
                  value={car.name}
                  id="name"
                  label="Name"
                  variant="outlined"
                  fullWidth
                  sx={{ mb: 2 }}
                  onChange={(event) =>
                    setCar({ ...car, name: event.target.value })
                  }
                />
                <TextField
                  value={car.addres}
                  id="addres"
                  label="Address"
                  variant="outlined"
                  fullWidth
                  sx={{ mb: 2 }}
                  onChange={(event) =>
                    setCar({ ...car, addres: event.target.value })
                  }
                />
  
                <TextField
                  value={car.cnp}
                  id="cnp"
                  label="CNP"
                  variant="outlined"
                  fullWidth
                  sx={{ mb: 2 }}
                  onChange={(event) =>
                    setCar({ ...car, cnp: event.target.value })
                  }
                />
  
                
                
  
                <Button type="submit">Update Owner</Button>
              </form>
            </CardContent>
            <CardActions></CardActions>
          </Card>
        )}
      </Container>
    );
  };