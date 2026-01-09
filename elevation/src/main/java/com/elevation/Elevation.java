package com.elevation;

public class Elevation {
    private static String prefix = "https://api.open-meteo.com/v1/elevation?";

    public static void main(String[] args) {
        WebService service = new WebService();

        service.setRequestProperty("User-Agent", "JavaClient"); // Buona norma per Open-Meteo
        service.setRequestProperty("Accept", "application/json");
        service.setRequestProperty("Accept-Charset", "UTF-8");

        float latitude = 38.0711786f;
        float longitude = 14.6377968f;

        String url = prefix + "latitude=" + latitude + "&longitude=" + longitude;

        System.out.println("Response: " + service.getData(url));
    }
}