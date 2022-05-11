Progetto:

Oggetti necessari:
    Controller:
        Pulsanti:
            Bup
            Bdown
            Bmake
        Potenziometro:
            Sugar

    View: 
        Display

    Sensori:
        Pir
            Rilevare presenza o meno
        Sonar
            Rilevare presenza o meno
        Termometro
            Rilevare guasti

    Servo motore:
        StatoProdotto

    Applicazione:
        CoffeeMachineManager
            Opera con il sistema

Funzionamento:
    Prodotti:
        Te (Nmax unità)
        Cioccolata (Nmax unità)
        Caffe (Nmax unità)
        
    Scelta del prodotto:
        Uso Bup e Bdown per selezione prodotto
        Pot per regolare zucchero
        Bmake per eseguire l'azione
            Aziona il servo motore che simula il processo
    
    Sleep mode:
        Se il sistema (Sonar + Pir) non detectano presenze, il sistema andra in risparmio energetico
    
    Applicazione:
        Monitora lo stato della macchina, la gestione delle scorte

    
Dettagli avanzati:

    Stato1 Avvio:
        Messaggio di benvenuto (un paio di secondi)
        Inizializzazione dei prodotti (fill Nmax i prodotti)

    Stato 1.5 Ready:
        Stampa ready quando pronta

    Stato2 Selezione prodotto:
        Stato 2.1 (Movimento fra prodotto):
            Bup, Bdown -> stampano il prodotto corrente su display (5sec -> Ready)

        Stato 2.2 (Selezione zucchero):
            Potsugar -> in contemporanea è possibile settare il livello di zucchero, resta fisso

        Stato 2.3 (Invio dell'ordine):
            Bmake -> invia l'ordine da processare

    Stato3 Esecuzione ordine:
        Stato 3.1 (Eseguendo ordine):
            Stampare messaggio "making a xxx" 
            Servo parte da 0° e arriva a 180° in un tempo Tmaking
        
        Stato 3.2 (Ordine completato):
            Quando il Tmaking (tempo attesa) è passato e la lancetta ha fatto 180° stampa su display "The xxx is ready"

        Stato 3.3 (Rimozione ordine):
            Se è presente qualcuno oltre 40 cm dal sonar il prodotto è stato rimosso, se è all'interno di 40 cm resta disponibile per Ttimeout secondi, dopodichè la macchina si resetterà

        Stato 3.4 (Reset macchina):
            Servo ritorna a 0°

    Stato4 Sleep mode:
        Se sono passati Tidle secondi di attesa e il Pir non rileva nulla, la macchina entra in sleep mode 
    
    Stato5 Prodotto finito: (Da integrare nello stato di selection come controllo)
        Stato 5.1 (Un prodotto finisce):
            Non è possibile selezionare quel prodotto 
            Stampa "Need to refill xxx"
        
        Stato 5.2 (Tutti i prodotti sono finiti):
            Entra in modalità assistenza
            Stampa "Assistance Required" (errore refill)

    Stato6 Assistenza:
        Assistance Required (errore refill) -> Basta eseguire il refill e può ripartire
        Assistane Required (errore recover) -> Basta premere il pulsante e l'azione si resetta

    Stato7 Controlli periodici:
        Ogni Tcheck secondi la macchina esegue un test
        Stato 7.1 (Test):
            Servo da 0 a 180° e ritorno
            Controllo temperatura misurata dal sensore (all'interno del range Temp_min Temp_max) -> se fuori range -> stampa "Assistance Required" (errore recover)

    Applicazione:
        Mostrare lo stato attuale della macchina
        Numero di prodotti ancora disponibili
        Numero di self-test eseguiti dal riavvio
        Pulsante refill 
        Pulsante recover

    Variabili consigliate:
        Tmaking = 10sec
        Ttimeout = 5sec
        Tidle = 60sec
        Tcheck = 180sec

        Temp_min = 17°
        Temp_max = 24°





Appunti di sviluppo:

Librerie e include path
Servo 
Timer

Relazione
Video

