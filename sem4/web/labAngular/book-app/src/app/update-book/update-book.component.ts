import { Component, OnInit } from '@angular/core';
import { Router } from '@angular/router';
import { Book } from 'src/models/Books';
import { GenericService } from '../generic.service';
@Component({
  selector: 'app-update-book',
  templateUrl: './update-book.component.html',
  styleUrls: ['./update-book.component.scss']
})
export class UpdateBookComponent implements OnInit{
  book: Book = {} as Book;

  constructor(private genericService: GenericService, private router: Router) { }

  ngOnInit(): void {
  }

  handleAdd(): void {
    this.genericService.updateBook(this.book).subscribe(() => {
      window.alert('Book updated successfully!');
      this.book = {} as Book;
    });
  }
  
}
