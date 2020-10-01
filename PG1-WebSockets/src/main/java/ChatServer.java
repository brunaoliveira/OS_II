import javax.websocket.server.ServerEndpoint;
import javax.websocket.Session;
import java.util.logging.Logger;
import javax.websocket.OnClose;
import javax.websocket.OnMessage;
import javax.websocket.OnOpen;

@ServerEndpoint("/chat")
public class ChatServer {

    private static final Logger LOGGER = Logger.getLogger();
    private static List<Session> openSessions = new ArrayList<Session>(); // open sessions
    // ou implementar com set? assim não repete identificador
    // Set<Session> openSessions = new HashSet<Session>();


//     Método anotado como @onOpen: Método que manipula o recebimento de conexões dos
// peers. Recebe como parâmetro um objeto Session e o armazena para que os outros
// métodos possam ter acesso. Toda vez que uma nova conexão for estabelecida, crie um
// novo registro de log indicando o identificador único da sessão atual, utilizando o método
// getId() para isso. 
    @onOpen
    public void openSession(Session newSession) {

        // se adicionou ao set a nova sessão 
        LOGGER.info("The session " + newSession.getId() + " was created.");
        // adicionar um erro se não adicionou?
    }


}
