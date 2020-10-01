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

        openSessions.add(newSession);
        // se adicionou ao set a nova sessão 
        LOGGER.info("The session " + newSession.getId() + " was created.");
        // log de erro se não adicionou?
    }

//     -Método anotado como @onClose: Método que é chamado quando uma sessão
// WebSocket está sendo fechada. Receba como parâmetro um objeto Session e crie um
// novo registro de log informando que a conexão identificada com o ID será fechada. Após
// isso, remova a sessão indicada da estrutura de dados que você definiu previamente. 
    @onClose
    public void closeSession(Session sessionClosing) {
        
        session.remove(sessionClosing);
        LOGGER.info("The session " + sessionClosing.getId() + " was closed.");
    }

//     -Método anotado como @onMessage: Método que é chamado para lidar com o
// recebimento de mensagens WebSocket. A princípio, implemente um método que recebe
// mensagens em formato de string e replique-as para os outros peers conectados. Essa
// funcionalidade pode ser implementada através do acesso a estrutura definida para abrigar
// as sessões estabelecidas e a invocação do método getBasicRemote() para cada uma
// delas, utilizando o método sendText() para encaminhar as mensagens. Ex:
// session.getBasicRemote().sendText(msg);
    @onMessage

}
