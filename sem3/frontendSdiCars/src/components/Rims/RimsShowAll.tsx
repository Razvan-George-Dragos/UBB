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
import { ReactNode, useEffect, useState } from "react"
import { Rim } from "../../models/Rims";
import ReadMoreIcon from "@mui/icons-material/ReadMore";
import EditIcon from "@mui/icons-material/Edit";
import DeleteForeverIcon from "@mui/icons-material/DeleteForever";
import AddIcon from "@mui/icons-material/Add"
import { DEV_BACKEND_API_URL } from "../../constants"
import { Paginator } from "../pagination/Pagination";
import { Car } from "../../models/Cars";


const StyledTableRow = styled(TableRow)`
  &:hover {
    background-color: #ecebed;
  }
`;
interface TableCellProps {
    children: ReactNode | Car;
  }
  

export const RimsShowAll = () => {
    const[loading, setLoading] = useState(true)
    const [cars, setCars] = useState<Rim[]>([]);
	const [page, setPage] = useState(1);
    const [pageSize, setPageSize] = useState(10);
    const [totalRows, setTotalRows] = useState(0);

    const [isLastPage, setIsLastPage] = useState(false)

    const setCurrentPage = (newPage: number) => {
        setPage(newPage);
    }

    const goToNextPage = () => {
        if (isLastPage) {
            return;
        }

        setPage(page + 1);
    }

    const goToPrevPage = () => {
        if (page === 1) {
            return;
        }

        setPage(page - 1);
	}

	const fetchCars = async () => {
		fetch(`${DEV_BACKEND_API_URL}/rims/${page}`)
      		.then(res => res.json())
      		.then(data => {setCars(data.data); setTotalRows(data.totalRows); setLoading(false);})
      		.catch(error => {
        		console.error(error);
        		setLoading(false);
       		});
	}

    useEffect(() => {
    	fetchCars();
		
    }, [page]);
    return (
      <Container>
			<h1>All rims</h1>

			{loading && <CircularProgress />}
			{!loading && cars.length === 0 && <p>No rims found</p>}
			{!loading && (
				<IconButton component={Link} sx={{ mr: 3 }} to={`/rims/add`}>
					<Tooltip title="Add a new rim" arrow>
						<AddIcon color="primary" />
					</Tooltip>
				</IconButton>
			)}
			{!loading && cars.length > 0 && (
				<><TableContainer component={Paper}>
					<Table sx={{ minWidth: 650 }} aria-label="simple table">
						<TableHead>
							<TableRow>
								<TableCell>#</TableCell>
								<TableCell align="right">Rim Brand</TableCell>
								<TableCell align="right">Rim Model</TableCell>
								<TableCell align="right">height</TableCell>
								<TableCell align="right">width</TableCell>
								<TableCell align="right">Car</TableCell>

								<TableCell align="center">Operations</TableCell>
							</TableRow>
						</TableHead>
						<TableBody>
							{cars.map((car, index) => (
								<StyledTableRow key={car.id}>
									<TableCell component="th" scope="row">
										{index + 1}
									</TableCell>
									<TableCell align="right">{car.rimBrand}</TableCell>
									<TableCell align="right">{car.rimModel}</TableCell>
									<TableCell component="th" scope="row">
										<Link to={`/rims/${car.id}/details`} title="View rim details">
											{car.height}
										</Link>
									</TableCell>
									<TableCell align="right">{car.width}</TableCell>
									<TableCell align="right">{car.carModel.id}</TableCell>

									<TableCell align="right">

										<IconButton
											component={Link}
											sx={{ mr: 3 }}
											to={`/rims/${car.id}/details`}>
											<Tooltip title="View rim details" arrow>
												<ReadMoreIcon color="primary" />
											</Tooltip>
										</IconButton>

										<IconButton component={Link} sx={{ mr: 3 }} to={`/rims/${car.id}/edit`}>
											<Tooltip title="Edit rim details" arrow>
												<EditIcon />
											</Tooltip>
										</IconButton>

										<IconButton component={Link} sx={{ mr: 3 }} to={`/rims/${car.id}/delete`}>
											<Tooltip title="Delete rim" arrow>
												<DeleteForeverIcon sx={{ color: "red" }} />
											</Tooltip>
										</IconButton>
									</TableCell>
								</StyledTableRow>
							))}
						</TableBody>
					</Table>
				</TableContainer><Paginator
						rowsPerPage={pageSize}
						totalRows={totalRows}
						currentPage={page}
						isFirstPage={page === 1}
						isLastPage={isLastPage}
						setPage={setCurrentPage}
						goToNextPage={goToNextPage}
						goToPrevPage={goToPrevPage} /></>
			)}
		</Container>
    )
  }