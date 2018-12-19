package oop.uebung10;

import java.io.BufferedInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.net.URL;
import java.net.URLConnection;
import java.util.ArrayList;
import java.util.List;

public class Downloader {

    private String url;
    private String content;

    public Downloader() {
    }

    public void setUrl(String url) {
        this.url = url;
    }

    public void setContent(String content) {
        this.content = content;
    }

    public String getUrl() {
        return url;
    }

    public String getContent() {
        return content;
    }

    public String download(String url_s) throws IOException {
        URL url = new URL(url_s);
        int i;
        URLConnection conn = url.openConnection();
        InputStream stream = conn.getInputStream();
        BufferedInputStream streamB = new BufferedInputStream(stream);

        List<Character> cList = new ArrayList<>();
        while ((i = streamB.read()) != -1) {
            cList.add((char) i);
        }
        streamB.close();
        char[] result = new char[cList.size()];

        for (i = 0; i < cList.size(); i++) {
            result[i] = cList.get(i);
        }

        this.setContent(new String(result));

        return this.getContent();
    }
}
