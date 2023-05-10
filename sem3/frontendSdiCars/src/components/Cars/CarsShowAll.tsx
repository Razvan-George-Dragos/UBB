import {
	TableContainer,
	Paper,
	Table,
	TableHead,
	TableRow,
	TableCell,
	TableBody,
	CircularProgress,
	Container,
	IconButton,
	Tooltip,
} from "@mui/material";
import axios from "axios";
import { styled } from '@mui/material/styles';
import { Link } from "react-router-dom";
import { useEffect, useState } from "react"
import { Car } from "../../models/Cars";
import ReadMoreIcon from "@mui/icons-material/ReadMore";
import EditIcon from "@mui/icons-material/Edit";
import DeleteForeverIcon from "@mui/icons-material/DeleteForever";
import AddIcon from "@mui/icons-material/Add"
import { DEV_BACKEND_API_URL } from "../../constants"

const StyledTableRow = styled(TableRow)`
  &:hover {
    background-color: #ecebed;
  }
`;

export const CarsShowAll = () => {
    const[loading, setLoading] = useState(true)
    const [cars, setCars] = useState<Car[]>([]);
    useEffect(() => {
    fetch(`${DEV_BACKEND_API_URL}/cars/`)
      .then(res => res.json())
      .then(data => {setCars(data); setLoading(false);})
      .catch(error => {
        console.error(error);
        setLoading(false);
        });
    }, []);
    return (
      <Container>
			<h1>All cars</h1>

			{loading && <CircularProgress />}
			{!loading && cars.length === 0 && <p>No cars found</p>}
			{!loading && (
				<IconButton component={Link} sx={{ mr: 3 }} to={`/cars/add`}>
					<Tooltip title="Add a new car" arrow>
						<AddIcon color="primary" />
					</Tooltip>
				</IconButton>
			)}
			{!loading && cars.length > 0 && (
				<TableContainer component={Paper}>
					<Table sx={{ minWidth: 650 }} aria-label="simple table">
						<TableHead>
							<TableRow>
								<TableCell>#</TableCell>
								<TableCell align="right">Car Brand</TableCell>
								<TableCell align="right">Model</TableCell>
								<TableCell align="right">Chasis nr</TableCell>
                                <TableCell align="right">Horse Power</TableCell>
                                <TableCell align="right">Year of registration</TableCell>
                            
								<TableCell align="center">Operations</TableCell>
							</TableRow>
						</TableHead>
						<TableBody>
							{cars.map((car, index) => (
								<StyledTableRow key={car.id}>
									<TableCell component="th" scope="row">
										{index + 1}
									</TableCell>
                                    <TableCell align="right">{car.brand}</TableCell>
                                    <TableCell align="right">{car.mod}</TableCell>
									<TableCell component="th" scope="row">
										<Link to={`/cars/${car.id}/details`} title="View car details">
											{car.chasisNr}
										</Link>
									</TableCell>
									<TableCell align="right">{car.hp}</TableCell>
									<TableCell align="right">{car.yearOfRegistration}</TableCell>
                                    
									<TableCell align="right">

										<IconButton
											component={Link}
											sx={{ mr: 3 }}
											to={`/cars/${car.id}/details`}>
											<Tooltip title="View car details" arrow>
												<ReadMoreIcon color="primary" />
											</Tooltip>
										</IconButton>

										<IconButton component={Link} sx={{ mr: 3 }} to={`/cars/${car.id}/edit`}>
											<Tooltip title="Edit car details" arrow>
												<EditIcon />
											</Tooltip>
										</IconButton>

										<IconButton component={Link} sx={{ mr: 3 }} to={`/cars/${car.id}/delete`}>
											<Tooltip title="Delete car" arrow>
												<DeleteForeverIcon sx={{ color: "red" }} />
											</Tooltip>
										</IconButton>
									</TableCell>
								</StyledTableRow>
							))}
						</TableBody>
					</Table>
				</TableContainer>
			)}
		</Container>
    )
  }
  
