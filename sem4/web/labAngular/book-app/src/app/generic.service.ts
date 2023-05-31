import { Injectable } from '@angular/core';
import { HttpClient, HttpParams } from '@angular/common/http';
import { Observable, filter, of } from 'rxjs';
import { catchError, map, tap } from 'rxjs';
import { Book } from 'src/models/Books';
@Injectable({
  providedIn: 'root'
})
export class GenericService {
  private backendUrl = 'http://localhost/labPHP';
  constructor(private http: HttpClient) { }
  getBooks(authorFilter?: string, titleFilter?: string): Observable<Book[]> {
    let url = `${this.backendUrl}/servicejsn.php?author=${authorFilter}&title=${titleFilter}`;
    return this.http.get<Book[]>(url);
  }
  addBook(book: Book): Observable<any> {
    
    return this.http.post(`${this.backendUrl}/addBookjsn.php`, book);
  }
  deleteBook(book_title: string): Observable<any> {
    return this.http.delete(`${this.backendUrl}/deleteBookjsn.php?book_title=${book_title}`);
  }
  updateBook(book: Book): Observable<any> {
    return this.http.put(`${this.backendUrl}/updateBookjsn.php`, book);
  }
}
