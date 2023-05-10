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
import { Owners } from "../../models/Owners";
import ReadMoreIcon from "@mui/icons-material/ReadMore";
import EditIcon from "@mui/icons-material/Edit";
import DeleteForeverIcon from "@mui/icons-material/DeleteForever";
import AddIcon from "@mui/icons-material/Add"
import { DEV_BACKEND_API_URL } from "../../constants"
import { Paginator } from "../pagination/Pagination";


const StyledTableRow = styled(TableRow)`
  &:hover {
    background-color: #ecebed;
  }
`;

export const OwnersShowAll = () => {
    const[loading, setLoading] = useState(true)
    const [cars, setCars] = useState<Owners[]>([]);
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
		fetch(`${DEV_BACKEND_API_URL}/owners/${page}`)
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
			<h1>All Owners</h1>

			{loading && <CircularProgress />}
			{!loading && cars.length === 0 && <p>No cars found</p>}
			{!loading && (
				<IconButton component={Link} sx={{ mr: 3 }} to={`/owners/add`}>
					<Tooltip title="Add a new owner" arrow>
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
								<TableCell align="right">Name</TableCell>
								<TableCell align="right">Address</TableCell>
								<TableCell align="right">CNP</TableCell>

								<TableCell align="center">Operations</TableCell>
							</TableRow>
						</TableHead>
						<TableBody>
							{cars.map((car, index) => (
								<StyledTableRow key={car.id}>
									<TableCell component="th" scope="row">
										{index + 1}
									</TableCell>
									<TableCell align="right">{car.name}</TableCell>
									<TableCell align="right">{car.addres}</TableCell>
									<TableCell component="th" scope="row">
										<Link to={`/owners/${car.id}/details`} title="View car details">
											{car.cnp}
										</Link>
									</TableCell>


									<TableCell align="right">

										<IconButton
											component={Link}
											sx={{ mr: 3 }}
											to={`/owners/${car.id}/details`}>
											<Tooltip title="View owner details" arrow>
												<ReadMoreIcon color="primary" />
											</Tooltip>
										</IconButton>

										<IconButton component={Link} sx={{ mr: 3 }} to={`/owners/${car.id}/edit`}>
											<Tooltip title="Edit car details" arrow>
												<EditIcon />
											</Tooltip>
										</IconButton>

										<IconButton component={Link} sx={{ mr: 3 }} to={`/owners/${car.id}/delete`}>
											<Tooltip title="Delete car" arrow>
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