#include "TwinsyType.h"
#ifdef STRATEGY
#include "Strategy/IHM/Menu/Match.h"
#include "Strategy/IHM/Inputs.h"
#include "Strategy/IHM/Screen.h"
#include "Strategy/Score.h"
#include "Core/MatchTimer.h"

bool Match::needDraw;
long Match::goStart;

void Match::init()
{
  needDraw = true;
  goStart = 0;
}

void Match::update()
{
  if (goStart == 0)
    goStart = millis();

  draw();
}

void Match::draw()
{
  int score(Score::getScore()), tempsRestant(MatchTimer::timeLeft() / 1000), nbrBadCRC(0);
  if (millis() - goStart < 1000)
  {
    Screen::lcd.clearBuffer();
    Screen::lcd.setFont(u8g2_font_logisoso58_tr);
    Screen::lcd.drawStr(18, 2, "GO!");
    Screen::lcd.sendBuffer();
  }
  else
  {
    Screen::lcd.clearBuffer();
    Screen::prepare();
    Screen::lcd.setFont(u8g2_font_inr42_mn);
    Screen::lcd.setCursor(8, 9);
    Screen::lcd.print(score);
    Screen::lcd.setFont(u8g2_font_4x6_tf);
    Screen::lcd.drawStr(0, 0, "Score:");
    Screen::lcd.drawStr(68, 0, "Temps:      sec");
    Screen::lcd.setCursor(93, 0);
    Screen::lcd.print(tempsRestant);
    Screen::lcd.drawStr(105, 57, "points");
    Screen::lcd.drawStr(0, 57, "NOK:");
    Screen::lcd.setCursor(20, 57);
    Screen::lcd.print(nbrBadCRC);
    Screen::lcd.sendBuffer();
  }
}

#endif