create database dbcrudgen;

use dbcrudgen;

create table packages
(
    id   INT NOT NULL IDENTITY (1,1) PRIMARY KEY,
    name text,
    path text
);

create index index_packages on packages (id);
create unique index unique_index_packages on packages (id);

create table classes
(
    id         INT NOT NULL IDENTITY (1,1) PRIMARY KEY,
    name       text,
    package_id int foreign key references packages (id)
);

create index index_classes on classes (id);
create unique index unique_index_classes on classes (id);

create table class_methods
(
    id          INT NOT NULL IDENTITY (1,1) PRIMARY KEY,
    name        text,
    return_type text,
    class_id    int foreign key references classes (id)
);

create index index_class_methods on class_methods (id);
create unique index unique_index_class_methods on class_methods (id);

create table class_variables
(
    id        INT NOT NULL IDENTITY (1,1) PRIMARY KEY,
    name      text,
    data_type text,
    class_id  int foreign key references classes (id)
);

create index index_class_variables on class_variables (id);
create unique index unique_index_class_variables on class_variables (id);

create table method_variables
(
    id             INT NOT NULL IDENTITY (1,1) PRIMARY KEY,
    name           text,
    data_type      text,
    method_id      int foreign key references class_methods (id),
    variable_index int
);

create index index_method_variables on method_variables (id);
create unique index unique_index_method_variables on method_variables (id);
