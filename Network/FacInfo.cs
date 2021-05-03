using System;
using System.Collections.Generic;
using System.Data.Entity;
using System.Linq;
using System.Web;
using WebApplication1.Models;

namespace WebApplication1.Context
{
    public class FacInfo:DbContext
    { 
        
        public FacInfo() : base(@"Data Source = (LocalDB)\MSSQLLocalDB; AttachDbFilename=C:\Users\KOSTA\source\repos\MyDatabase.mdf;Integrated Security = True; Connect Timeout = 30") 
        { }
        public DbSet<Fac> FacInfos { get; set; }
    }
}