import { Component, OnInit } from '@angular/core';
import { GenericService } from '../generic.service';
import { Book } from 'src/models/Books';
import { Router } from '@angular/router';
@Component({
  selector: 'app-add-book',
  templateUrl: './add-book.component.html',
  styleUrls: ['./add-book.component.scss']
})
export class AddBookComponent implements OnInit {
  book: Book = {} as Book;

  constructor(private genericService: GenericService, private router: Router){ }
  ngOnInit(): void {
    
  }
  handleAdd(): void {
    this.genericService.addBook(this.book).subscribe(() => {
      window.alert('Book added successfully!');
      this.book = {} as Book;
    });
  }
}
