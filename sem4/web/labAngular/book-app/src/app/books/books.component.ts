import { Component, OnInit } from '@angular/core';
import { Router } from '@angular/router';
import { Book } from 'src/models/Books';
import { GenericService } from '../generic.service';
@Component({
  selector: 'app-books',
  templateUrl: './books.component.html',
  styleUrls: ['./books.component.scss']
})
export class BooksComponent implements OnInit{
  authorFilter?: string = "book_author";
  titleFilter?: string = "book_title";
books: Book[] = [];
constructor(private genericService: GenericService) { }
ngOnInit(): void{
  this.handleBrowse;
}
handleBrowse(): void{
  this.genericService.getBooks(this.authorFilter, this.titleFilter).subscribe(
    (books: Book[]) => {
      this.books = books;
      
     
    });
}
}
