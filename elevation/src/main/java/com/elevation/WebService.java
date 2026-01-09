package com.elevation;

import java.io.*;
import java.net.*;
import java.util.*;

public class WebService {
  private Map<String, String> headers = new HashMap<>();

  public void setRequestProperty(String key, String value) {
    headers.put(key, value);
  }

  public String getData(String urlString) {
    StringBuilder result = new StringBuilder();
    try {
      URL url = URI.create(urlString).toURL();
      HttpURLConnection conn = (HttpURLConnection) url.openConnection();
      conn.setRequestMethod("GET");

      for (Map.Entry<String, String> entry : headers.entrySet()) {
        conn.setRequestProperty(entry.getKey(), entry.getValue());
      }

      BufferedReader rd = new BufferedReader(new InputStreamReader(conn.getInputStream()));
      String line;
      while ((line = rd.readLine()) != null) {
        result.append(line);
      }
      rd.close();
    } catch (Exception e) {
      e.printStackTrace();
      return null;
    }
    return result.toString();
  }
}
