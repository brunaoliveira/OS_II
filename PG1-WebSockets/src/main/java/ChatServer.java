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
    private static ArrayList<Session> openSessions = new ArrayList<Session>(); // open sessions
    // ou implementar com set? assim não repete identificador
    // Set<Session> openSessions = new HashSet<Session>();

    
    @OnOpen
    public void openSession(Session newSession) {
        openSessions.add(newSession);
        // se adicionou ao set a nova sessão 
        LOGGER.info("The session " + newSession.getId() + " was created.");
        // log de erro se não adicionou?
    }

    
    @OnClose
    public void closeSession(Session sessionClosing) {
        openSessions.remove(sessionClosing);
        LOGGER.info("The session " + sessionClosing.getId() + " was closed.");
    }


    @OnMessage
    public void sendMessage(String msg) throws IOException {
        for (Session session : openSessions) {
            session.getBasicRemote().sendText(msg);
        }
    }
    
}
