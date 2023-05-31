import { NgModule } from '@angular/core';
import { RouterModule, Routes } from '@angular/router';
import { BooksComponent } from './books/books.component';
import { AddBookComponent } from './add-book/add-book.component';
import { DeleteBookComponent } from './delete-book/delete-book.component';
import { UpdateBookComponent } from './update-book/update-book.component';
const routes: Routes = [
  { path: 'books', component: BooksComponent},
  { path: 'add-book', component: AddBookComponent},
  { path: 'books/delete/:book_title', component: DeleteBookComponent},
  { path: 'books/update/:book_title', component: UpdateBookComponent},
];

@NgModule({
  imports: [RouterModule.forRoot(routes)],
  exports: [RouterModule]
})
export class AppRoutingModule { }
