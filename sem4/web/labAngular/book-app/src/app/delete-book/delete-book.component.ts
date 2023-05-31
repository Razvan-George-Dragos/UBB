import { Component, OnInit } from '@angular/core';
import { Router } from '@angular/router';
import { GenericService } from '../generic.service';
@Component({
  selector: 'app-delete-book',
  templateUrl: './delete-book.component.html',
  styleUrls: ['./delete-book.component.scss']
})
export class DeleteBookComponent implements OnInit{
  book_title: string ="";
  constructor(private genericService: GenericService, private router: Router) { }
  ngOnInit(): void {
    throw new Error('Method not implemented.');
  }
  
  
  handleDelete(): void{
    this.genericService.deleteBook(this.book_title).subscribe(() => {
      window.alert('Book deleted successfully!');
      })
    };
}
