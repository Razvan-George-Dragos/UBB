import {
    Autocomplete,
    Button,
    Card,
    CardActions,
    CardContent,
    CircularProgress,
    Container,
    IconButton,
    TextField,
  } from "@mui/material";
import { useCallback, useEffect, useState } from "react";
import { Link, useNavigate, useParams } from "react-router-dom";
import ArrowBackIcon from "@mui/icons-material/ArrowBack";
import axios from "axios";
import { Rim } from "../../models/Rims";
import { DEV_BACKEND_API_URL } from "../../constants"
import { Car } from "../../models/Cars";
import { debounce } from "lodash";

export const RimsUpdate = () => {
    const navigate = useNavigate();
    const { carId } = useParams();
  
    //const [loading, setLoading] = useState(true);
    //const [car, setCar] = useState<Rim | null>(null);
    const [car, setCar] = useState({
		rimBrand: "",
        rimModel:"",
		height: 1,
        width: 1,
        carModel: 1,
	});
    const [carss, setCarss] = useState<Car[]>([]);

    const fetchSuggestions = async (query: string) => {
		try {
			let url = `${DEV_BACKEND_API_URL}/carOrdByBrand/${query}`;
			await fetch(url).then(async(response)=>{
				const jsn = await response.json();
				setCarss(jsn);
				console.log(jsn);
			}); 
			//const response = await fetch(url);
			//const { count, next, previous, results } = await response.json();
			//setCarss(results);
			//console.log(results);
		} catch (error) {
			console.error("Error fetching suggestions:", error);
		}
	};

    const debouncedFetchSuggestions = useCallback(debounce(fetchSuggestions, 500), []);

	useEffect(() => {
		return () => {
			debouncedFetchSuggestions.cancel();
		};
	}, [debouncedFetchSuggestions]);
	

    const handleInputChange = (event: any, value: any, reason: any) => {
		console.log("input", value, reason);

		if (reason === "input") {
			debouncedFetchSuggestions(value);
		}
	};
  
    
  
    const updateCar = async (event: { preventDefault: () => void }) => {
      event.preventDefault();
      try {
        await axios.put(`${DEV_BACKEND_API_URL}/rims/?id=${carId}`, car);
        navigate(`/rims/`);
      } catch (error) {
        console.log(error);
      }
    };
  
  
    return (
      <Container>
        (
          <Card>
            <CardContent>
              <IconButton
                component={Link}
                sx={{ mr: 3 }}
                to={`/rims/`}
              >
                <ArrowBackIcon />
              </IconButton>{" "}
              <form onSubmit={updateCar}>
              <TextField
							id="rimBrand"
							label="Rim Brand"
							variant="outlined"
							fullWidth
							sx={{ mb: 2 }}
							onChange={(event: React.ChangeEvent<HTMLInputElement>)=> setCar({ ...car, rimBrand: event.target.value })}
						/>
                        <TextField
							id="rimModel"
							label="Model"
							variant="outlined"
							fullWidth
							sx={{ mb: 2 }}
							onChange={(event: React.ChangeEvent<HTMLInputElement>) => setCar({ ...car, rimModel: event.target.value })}
						/>
						<TextField
							id="height"
							label="Height"
							variant="outlined"
							fullWidth
							sx={{ mb: 2 }}
							onChange={(event: React.ChangeEvent<HTMLInputElement>) => setCar({ ...car, height: Number(event.target.value) })}
						/>
						 <TextField
							id="width"
							label="Width"
							variant="outlined"
							fullWidth
							sx={{ mb: 2 }}
							onChange={(event: React.ChangeEvent<HTMLInputElement>) => setCar({ ...car, width: Number(event.target.value) })}
						/>
                         <Autocomplete
							id="carModel"
							options={carss}
							renderInput={(params) => <TextField {...params} label="Car" variant="outlined" />}
							getOptionLabel={(option) => `${option.brand} - ${option.mod}`}
							//filterOptions={(options, state) => options.filter((option) => option.brand.toLowerCase().includes(state.inputValue.toLowerCase()))}

							onInputChange={handleInputChange}
							onChange={(event, value) => {
								if (value) {
									console.log(value);
									setCar({ ...car, carModel: value.id });
								}
							}}
							
						/> 
                <Button type="submit">Update Rim</Button>
              </form>
            </CardContent>
            <CardActions></CardActions>
          </Card>
        )
      </Container>
    );
  };