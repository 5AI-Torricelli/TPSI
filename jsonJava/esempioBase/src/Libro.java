public class Libro {
  private String genere;
  private String titolo;
  private String autore;
  private float prezzo;

  public Libro(String genere, String titolo, String autore, float prezzo) {
    this.genere = genere;
    this.titolo = titolo;
    this.autore = autore;
    this.prezzo = prezzo;
  }

  public String getTitolo() {
    return titolo;
  }

  public void setTitolo(String titolo) {
    this.titolo = titolo;
  }

  public String getAutore() {
    return autore;
  }

  public void setAutore(String autore) {
    this.autore = autore;
  }

  public String getGenere() {
    return genere;
  }

  public void setGenere(String genere) {
    this.genere = genere;
  }

  public float getPrezzo() {
    return prezzo;
  }

  public void setPrezzo(float prezzo) {
    this.prezzo = prezzo;
  }

  @Override
  public String toString() {
    return "Libro{" +
        "genere='" + genere + '\'' +
        ", titolo='" + titolo + '\'' +
        ", autore='" + autore + '\'' +
        ", prezzo='" + prezzo + '\'' +
        '}';
  }
}
