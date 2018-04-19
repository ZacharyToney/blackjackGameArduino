const char MAIN_page[] PROGMEM = R"=====(<!DOCTYPE html>
<!DOCTYPE html>
<html>
	<head>
		<title>Zachary Toney's Blackjack Game</title>

		
		<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.3.1/jquery.min.js"></script>
	  <script class="deckLogic" type="text/javascript">
	    class Deck{
	    constructor(){
	      this.deck = [];
	      this.reset();
	      this.shuffle();
	    }

	    reset(){
	      this.deck = [];

	      const suits = ['Hearts', 'Spades', 'Clubs', 'Diamonds'];
	      const values = ['Ace', 2, 3, 4, 5, 6, 7, 8, 9, 10, 'Jack', 'Queen', 'King'];

	      for (let suit in suits) {
	        for (let value in values) {
	          this.deck.push(`${values[value]} of ${suits[suit]}`);
	        }
	      }
	    }

	    shuffle(){
	      const { deck } = this;
	      let m = deck.length, i;

	      while(m){
	        i = Math.floor(Math.random() * m--);

	        [deck[m], deck[i]] = [deck[i], deck[m]];
	      }

	      return this;
	    }

	    deal(){
	      return this.deck.pop();
	    }
	  }

	  const deck1 = new Deck();
	  </script>

		<script class="functionsForTable" type="text/javascript">

			$(document).ready(function(){$(".table").fadeIn(2250,playerStartAndStartButton());});
			var playerScore = 0;
			var faceCardTwo = 0;

			function playerStartAndStartButton() {
				setTimeout(
				  function() 
				  {
						$(".player").fadeIn(2250);
						$(".dealer").fadeIn(2250);
						$(".playerCards").fadeIn(2250);
						$(".startButton").css('display', 'inline-block');	
						
				  }, 2000);
			}

			function hitButtonClicked(){
				$(".playerCards").append("<div class='playerCardButton' style='display:inline-block;'><p>"+deck1.deal()+"</p></div>");
				checkIfPlayerHas21();
			}

			function startGame() {
				playerScore = 0;
				faceCardTwo = 0;
				$(".startButton").css("display",'none');
				$(".hitButton").css('display', 'inline-block');
				$(".standButton").css('display', 'inline-block');
				$(".dealerCardButton").css('display', 'inline-block');
				$(".playerCardButton").css('display', 'inline-block');
				$(".dealer").append("<div class='dealerCardButton' style='display:inline-block;'><p id='dealerHidden' style='color:white;'>"+deck1.deal()+"</p></div>");
				$(".dealer").append("<div class='dealerCardButton' style='display:inline-block;'><p id='dealerHidden' style='color:#e67e22;'>"+deck1.deal()+"</p></div>");
				$(".playerCards").append("<div class='playerCardButton' style='display:inline-block;'><p>"+deck1.deal()+"</p></div>");
				$(".playerCards").append("<div class='playerCardButton' style='display:inline-block;'><p>"+deck1.deal()+"</p></div>");
				checkIfPlayerHas21();
			}

			function checkIfPlayerHas21(){
				var playerCards = $(".playerCardButton").text();
				
				if( playerCards.indexOf('Jack') >= 0){
				  playerScore += 10;
				  faceCardTwo++;
				}
				if( playerCards.indexOf('Queen') >= 0){
				  playerScore += 10;
				  faceCardTwo++;
				}
				if( playerCards.indexOf('King') >= 0){
				  playerScore += 10;
				  faceCardTwo++;
				}
				if( playerCards.indexOf('Ace') >= 0){
					faceCardTwo++;
					var count = (playerCards.match(/Ace/g) || []).length;
					if (count > 1){
						faceCardTwo++;
						playerScore = (count - 1) + 11;
					}
					else{
				  playerScore += 11;
				  }
				}

				if (faceCardTwo >= 2) {
					if (playerScore > 21) {
						alert("You Busted!");
						$(".playerCardButton").remove();
						$(".dealerCardButton").remove();
						$(".hitButton").css("display",'none');
						$(".standButton").css("display",'none');
						playerStartAndStartButton();
					}
					else if(playerScore<21){
						alert("You didn't bust yet!");
					}
					else{
						alert("You got 21!(Blackjack!)");
						$(".playerCardButton").remove();
						$(".dealerCardButton").remove();
						$(".hitButton").css("display",'none');
						$(".standButton").css("display",'none');
						playerStartAndStartButton();
					}
				}
				else{
					var numbers = playerCards.match(/\d+/g).map(Number);
					for (i = 0; i < numbers.length; i++) {
						playerScore += numbers[i];
					}
					if (playerScore > 21) {
						alert("You Busted!");
						$(".playerCardButton").remove();
						$(".dealerCardButton").remove();
						$(".hitButton").css("display",'none');
						$(".standButton").css("display",'none');
						playerStartAndStartButton();
					}
					else if(playerScore<21){
						alert("You didn't bust yet!");
					}
					else{
						alert("You got 21!(Blackjack!)");
						$(".playerCardButton").remove();
						$(".dealerCardButton").remove();
						$(".hitButton").css("display",'none');
						$(".standButton").css("display",'none');
						playerStartAndStartButton();
					}
					console.log(playerScore);
				}
				playerScore = 0;
			}
		</script>

		<style type="text/css">

			body{
				background:url("http://1.bp.blogspot.com/-sD74A2hCNKE/UJhmT4ZoDII/AAAAAAAAD0A/lv-tithPdX0/s1600/Seamless+carpet+fabric+brown+pattern+texture.jpg");
			}

			.dealer{
				display: none;
		    position: relative;
		    border-radius: 1em;
		    border-color: cyan;
		    border-style: solid;
		    border-width: 0.7em;
		    top: 3em;
		    left: 0;
		    height: 8em;
		    width: 60em;
		    margin: 0 auto 0 auto;
			}

			.playerCards{
				display: none;
		    position: relative;
		    border-radius: 1em;
		    border-color: cyan;
		    border-style: solid;
		    border-width: 0.7em;
		    top: 4em;
		    left: 0;
		    height: 8em;
		    width: 60em;
		    margin: 0 auto 0 auto;
			}

			.player{
				display: none;
		    position: relative;
		    border-radius: 1em;
		    border-color: cyan;
		    border-style: solid;
		    border-width: 0.7em;
		    top: 5em;
		    left: 0;
		    height: 8em;
		    width: 60em;
		    margin: 0 auto 0 auto;
			}
			.startButton{
				display: none;
		    background: black;
		    height: 53%;
		    width: 10%;
			  position:relative;
			  color:#ecf0f1;
			  text-decoration:none;
			  border-radius:5px;
			  border:solid 1px #f39c12;
			  background:#e67e22;
			  text-align:center;
			  padding:16px 18px 14px;
			  margin: 12px;
			  -webkit-transition: all 0.1s;
				-moz-transition: all 0.1s;
				transition: all 0.1s;
			  -webkit-box-shadow: 0px 6px 0px #d35400;
			  -moz-box-shadow: 0px 6px 0px #d35400;
			  box-shadow: 0px 6px 0px #d35400;
			}
			.startButton:active{
			    -webkit-box-shadow: 0px 2px 0px #d35400;
			    -moz-box-shadow: 0px 2px 0px #d35400;
			    box-shadow: 0px 2px 0px #d35400;
			    position:relative;
			    top:4px;
			}
			.hitButton{
				display: none;
		    background: black;
		    height: 53%;
		    width: 10%;
			  position:relative;
			  color:#ecf0f1;
			  text-decoration:none;
			  border-radius:5px;
			  border:solid 1px #f39c12;
			  background:#e67e22;
			  text-align:center;
			  padding:16px 18px 14px;
			  margin: 12px;
			  -webkit-transition: all 0.1s;
				-moz-transition: all 0.1s;
				transition: all 0.1s;
			  -webkit-box-shadow: 0px 6px 0px #d35400;
			  -moz-box-shadow: 0px 6px 0px #d35400;
			  box-shadow: 0px 6px 0px #d35400;
			}
			.hitButton:active{
			    -webkit-box-shadow: 0px 2px 0px #d35400;
			    -moz-box-shadow: 0px 2px 0px #d35400;
			    box-shadow: 0px 2px 0px #d35400;
			    position:relative;
			    top:4px;
			}
			.standButton{
				display: none;
		    background: black;
		    height: 53%;
		    width: 10%;
			  position:relative;
			  color:#ecf0f1;
			  text-decoration:none;
			  border-radius:5px;
			  border:solid 1px #f39c12;
			  background:#e67e22;
			  text-align:center;
			  padding:16px 18px 14px;
			  margin: 12px;
			  -webkit-transition: all 0.1s;
				-moz-transition: all 0.1s;
				transition: all 0.1s;
			  -webkit-box-shadow: 0px 6px 0px #d35400;
			  -moz-box-shadow: 0px 6px 0px #d35400;
			  box-shadow: 0px 6px 0px #d35400;
			}
			.standButton:active{
			    -webkit-box-shadow: 0px 2px 0px #d35400;
			    -moz-box-shadow: 0px 2px 0px #d35400;
			    box-shadow: 0px 2px 0px #d35400;
			    position:relative;
			    top:4px;
			}
			.splitButton{
				display: none;
		    background: black;
		    height: 53%;
		    width: 10%;
			  position:relative;
			  color:#ecf0f1;
			  text-decoration:none;
			  border-radius:5px;
			  border:solid 1px #f39c12;
			  background:#e67e22;
			  text-align:center;
			  padding:16px 18px 14px;
			  margin: 12px;
			  -webkit-transition: all 0.1s;
				-moz-transition: all 0.1s;
				transition: all 0.1s;
			  -webkit-box-shadow: 0px 6px 0px #d35400;
			  -moz-box-shadow: 0px 6px 0px #d35400;
			  box-shadow: 0px 6px 0px #d35400;
			}
			.splitButton:active{
			    -webkit-box-shadow: 0px 2px 0px #d35400;
			    -moz-box-shadow: 0px 2px 0px #d35400;
			    box-shadow: 0px 2px 0px #d35400;
			    position:relative;
			    top:4px;
			}
			.doubleDownButton{
				display: none;
		    background: black;
		    height: 53%;
		    width: 10%;
			  position:relative;
			  color:#ecf0f1;
			  text-decoration:none;
			  border-radius:5px;
			  border:solid 1px #f39c12;
			  background:#e67e22;
			  text-align:center;
			  padding:16px 18px 14px;
			  margin: 12px;
			  -webkit-transition: all 0.1s;
				-moz-transition: all 0.1s;
				transition: all 0.1s;
			  -webkit-box-shadow: 0px 6px 0px #d35400;
			  -moz-box-shadow: 0px 6px 0px #d35400;
			  box-shadow: 0px 6px 0px #d35400;
			}
			.doubleDownButton:active{
			    -webkit-box-shadow: 0px 2px 0px #d35400;
			    -moz-box-shadow: 0px 2px 0px #d35400;
			    box-shadow: 0px 2px 0px #d35400;
			    position:relative;
			    top:4px;
			}
			.dealerCardButton{
				display: none;
		    background: black;
		    height: 53%;
		    width: 10%;
			  position:relative;
			  color:#ecf0f1;
			  text-decoration:none;
			  border-radius:5px;
			  border:solid 1px #f39c12;
			  background:#e67e22;
			  text-align:center;
			  padding:16px 18px 14px;
			  margin: 12px;
			  -webkit-transition: all 0.1s;
				-moz-transition: all 0.1s;
				transition: all 0.1s;
			  -webkit-box-shadow: 0px 6px 0px #d35400;
			  -moz-box-shadow: 0px 6px 0px #d35400;
			  box-shadow: 0px 6px 0px #d35400;
			}
			.playerCardButton{
				display: none;
		    background: black;
		    height: 53%;
		    width: 10%;
			  position:relative;
			  color:#ecf0f1;
			  text-decoration:none;
			  border-radius:5px;
			  border:solid 1px #f39c12;
			  background:#e67e22;
			  text-align:center;
			  padding:16px 18px 14px;
			  margin: 12px;
			  -webkit-transition: all 0.1s;
				-moz-transition: all 0.1s;
				transition: all 0.1s;
			  -webkit-box-shadow: 0px 6px 0px #d35400;
			  -moz-box-shadow: 0px 6px 0px #d35400;
			  box-shadow: 0px 6px 0px #d35400;
			}

			.table{
				display: none;
		    height: 37em;
		    width: 73em;
		    background: url(https://i.imgur.com/dAIZPHY.jpg);
		    position: relative;
		    border-radius: 13em;
		    top: 4em;
		    bottom: 0;
		    left: 0;
		    right: 0;
		    margin: auto;
			}
		</style>
	</head>
	<body>

		<div class="table">
			<div class="dealer">
			</div>

			<div class="playerCards">
			</div>

			<div class="player">
				<div class="startButton" onclick="startGame()">
					<p>Start</p>
				</div>
				<div class="hitButton" onclick="hitButtonClicked()">
					<p>Hit</p>
				</div>
				<div class="standButton">
					<p>Stand</p>
				</div>
				<div class="splitButton">
					<p>Split</p>
				</div>
				<div class="doubleDownButton">
					<p>Double Down</p>
				</div>
			</div>
		</div>

	</body>
</html>
)=====";