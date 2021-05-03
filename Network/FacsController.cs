using System;
using System.Collections.Generic;
using System.Data;
using System.Data.Entity;
using System.Linq;
using System.Net;
using System.Web;
using System.Web.Mvc;
using WebApplication1.Context;
using WebApplication1.Models;

namespace WebApplication1.Controllers
{
    public class FacsController : Controller
    {
        private FacInfo db = new FacInfo();

        // GET: Facs
        public ActionResult Index()
        {
            return View(db.FacInfos.ToList());
        }

        // GET: Facs/Details/5
        public ActionResult Details(int? id)
        {
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            Fac fac = db.FacInfos.Find(id);
            if (fac == null)
            {
                return HttpNotFound();
            }
            return View(fac);
        }

        // GET: Facs/Create
        public ActionResult Create()
        {
            return View();
        }

        // POST: Facs/Create
        // 초과 게시 공격으로부터 보호하려면 바인딩하려는 특정 속성을 사용하도록 설정하세요. 
        // 자세한 내용은 https://go.microsoft.com/fwlink/?LinkId=317598을(를) 참조하세요.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Create([Bind(Include = "id,fCode,fName,fDesc")] Fac fac)
        {
            if (ModelState.IsValid)
            {
                db.FacInfos.Add(fac);
                db.SaveChanges();
                return RedirectToAction("Index");
            }

            return View(fac);
        }

        // GET: Facs/Edit/5
        public ActionResult Edit(int? id)
        {
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            Fac fac = db.FacInfos.Find(id);
            if (fac == null)
            {
                return HttpNotFound();
            }
            return View(fac);
        }

        // POST: Facs/Edit/5
        // 초과 게시 공격으로부터 보호하려면 바인딩하려는 특정 속성을 사용하도록 설정하세요. 
        // 자세한 내용은 https://go.microsoft.com/fwlink/?LinkId=317598을(를) 참조하세요.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Edit([Bind(Include = "id,fCode,fName,fDesc")] Fac fac)
        {
            if (ModelState.IsValid)
            {
                db.Entry(fac).State = EntityState.Modified;
                db.SaveChanges();
                return RedirectToAction("Index");
            }
            return View(fac);
        }

        // GET: Facs/Delete/5
        public ActionResult Delete(int? id)
        {
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            Fac fac = db.FacInfos.Find(id);
            if (fac == null)
            {
                return HttpNotFound();
            }
            return View(fac);
        }

        // POST: Facs/Delete/5
        [HttpPost, ActionName("Delete")]
        [ValidateAntiForgeryToken]
        public ActionResult DeleteConfirmed(int id)
        {
            Fac fac = db.FacInfos.Find(id);
            db.FacInfos.Remove(fac);
            db.SaveChanges();
            return RedirectToAction("Index");
        }

        protected override void Dispose(bool disposing)
        {
            if (disposing)
            {
                db.Dispose();
            }
            base.Dispose(disposing);
        }
    }
}
