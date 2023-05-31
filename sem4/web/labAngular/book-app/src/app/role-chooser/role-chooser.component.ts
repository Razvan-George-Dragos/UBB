import { Component, OnInit } from '@angular/core';
import { Location } from '@angular/common';

@Component({
  selector: 'app-role-chooser',
  templateUrl: './role-chooser.component.html',
  styleUrls: ['./role-chooser.component.scss']
})
export class RoleChooserComponent {
  constructor(private location: Location) { }
  protected active: string = 'home';
  ngOnInit(): void {
    let url = this.location.path();

    if (url.startsWith('/')) {
      url = url.substring(1);
    }

    if (url.indexOf('/') > -1) {
      url = url.substring(0, url.indexOf('/'));
    }

    this.makeButtonActive(url);
  } 

  makeButtonActive(button: string): void {
    this.active = button;
  }

}
