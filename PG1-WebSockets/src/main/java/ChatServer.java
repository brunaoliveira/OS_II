import javax.websocket.server.ServerEndpoint;
import javax.websocket.Session;
import javax.websocket.OnClose;
import javax.websocket.OnMessage;
import javax.websocket.OnOpen;
import java.util.logging.Logger;
import java.util.ArrayList;
import java.io.*;

@ServerEndpoint("/chat")
public class ChatServer {
    private static final Logger LOGGER = Logger.getLogger(ChatServer.class.getName());
    private static ArrayList<Session> openSessions = new ArrayList<Session>();
    
    @OnOpen
    public void openSession(Session newSession) {
        openSessions.add(newSession);
        LOGGER.info("The session " + newSession.getId() + " was created.");
    }

    
    @OnClose
    public void closeSession(Session sessionClosing) {
        LOGGER.info("The session " + sessionClosing.getId() + " was closed.");
        openSessions.remove(sessionClosing);
    }


    @OnMessage
    public void sendMessage(String msg) throws IOException {
        for (Session session : openSessions) {
            try {
                session.getBasicRemote().sendText(msg);
            } catch(IOException e){
                System.err.println(e.getMessage());
            }
        }
    }
    
}
