package scuola.testservlet;

import java.io.*;
import jakarta.servlet.*;
import jakarta.servlet.http.*;

public class TestServlet extends HttpServlet {
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        response.setContentType("text/xml;charset=UTF-8");
        PrintWriter out = response.getWriter();
        try {
            out.println("<?xml version=\"1.0\" encoding=\"UTF-8\"?>");
            out.println("<message>");
            out.println("Hello World!");
            out.print("</message>");
        } finally {
            out.close();
        }
    }

    public String getServletInfo() {
        return "Test servlet";
    }
}