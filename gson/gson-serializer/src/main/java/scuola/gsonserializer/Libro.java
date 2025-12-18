package scuola.gsonserializer;

public class Libro {
   private String titolo;
   private String autore;
   private float prezzo;

   /*
    * public Libro() {
    * this.titolo = "";
    * this.autore = "";
    * this.prezzo = 0;
    * }
    */

   public Libro(String titolo, String autore, float prezzo) {
      this.titolo = titolo;
      this.autore = autore;
      this.prezzo = prezzo;
   }

   public Libro(Libro libro) {
      this.titolo = libro.titolo;
      this.autore = libro.autore;
      this.prezzo = libro.prezzo;
   }

   public String getTitolo() {
      return titolo;
   }

   public String getAutore() {
      return autore;
   }

   public float getPrezzo() {
      return prezzo;
   }

   public void setTitolo(String titolo) {
      this.titolo = titolo;
   }

   public void setAutore(String autore) {
      this.autore = autore;
   }

   public void setPrezzo(float prezzo) {
      this.prezzo = prezzo;
   }

   public String toString() {
      return autore + ", \"" + titolo + "\" (" + prezzo + "€)";
   }
}
