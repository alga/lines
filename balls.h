#ifndef LINES_BALLS_H
#define LINES_BALLS_H

/* XPM */
static char * ball1_xpm[] = {
"22 22 169 2",
"  	c None",
". 	c #B34A4A",
"+ 	c #A72020",
"@ 	c #9D0B0B",
"# 	c #970B0B",
"$ 	c #972121",
"% 	c #9F4C4C",
"& 	c #B41F1F",
"* 	c #B30606",
"= 	c #B00606",
"- 	c #AB0707",
"; 	c #A30707",
"> 	c #9A0808",
", 	c #900909",
"' 	c #850A0A",
") 	c #842323",
"! 	c #BF5E5E",
"~ 	c #B80606",
"{ 	c #BE0505",
"] 	c #C10505",
"^ 	c #AF0606",
"/ 	c #A50707",
"( 	c #8E0909",
"_ 	c #810A0A",
": 	c #740B0B",
"< 	c #966161",
"[ 	c #BE5E5E",
"} 	c #BA0505",
"| 	c #C40404",
"1 	c #CC0404",
"2 	c #D00303",
"3 	c #A20707",
"4 	c #950808",
"5 	c #880A0A",
"6 	c #7A0B0B",
"7 	c #6C0C0C",
"8 	c #906262",
"9 	c #B60606",
"0 	c #C30505",
"a 	c #CF0404",
"b 	c #D90303",
"c 	c #DF0202",
"d 	c #A90707",
"e 	c #9B0808",
"f 	c #8D0909",
"g 	c #7F0A0A",
"h 	c #700C0C",
"i 	c #620D0D",
"j 	c #B11F1F",
"k 	c #BB0505",
"l 	c #CA0404",
"m 	c #D70303",
"n 	c #E40202",
"o 	c #ED0101",
"p 	c #BC0505",
"q 	c #AD0606",
"r 	c #9F0808",
"s 	c #820A0A",
"t 	c #730B0B",
"u 	c #640D0D",
"v 	c #642626",
"w 	c #CD0404",
"x 	c #DB0202",
"y 	c #EA0101",
"z 	c #F80000",
"A 	c #F90000",
"B 	c #DC0202",
"C 	c #A00808",
"D 	c #920909",
"E 	c #830A0A",
"F 	c #650D0D",
"G 	c #560E0E",
"H 	c #B14A4A",
"I 	c #AE0606",
"J 	c #BD0505",
"K 	c #DA0303",
"L 	c #E80101",
"M 	c #F40000",
"N 	c #910909",
"O 	c #754F4F",
"P 	c #A32020",
"Q 	c #B90505",
"R 	c #C70404",
"S 	c #D40303",
"T 	c #E60202",
"U 	c #9D0808",
"V 	c #8F0909",
"W 	c #800A0A",
"X 	c #720B0B",
"Y 	c #630D0D",
"Z 	c #540E0E",
"` 	c #572727",
" .	c #980B0B",
"..	c #A60707",
"+.	c #BF0505",
"@.	c #D20303",
"#.	c #D80303",
"$.	c #D30303",
"%.	c #980808",
"&.	c #8B0909",
"*.	c #7C0B0B",
"=.	c #6E0C0C",
"-.	c #600D0D",
";.	c #520E0E",
">.	c #451212",
",.	c #930C0C",
"'.	c #9E0808",
").	c #AA0707",
"!.	c #B50606",
"~.	c #C50404",
"{.	c #C90404",
"].	c #770B0B",
"^.	c #690C0C",
"/.	c #5C0D0D",
"(.	c #4E0F0F",
"_.	c #411313",
":.	c #922121",
"<.	c #B10606",
"[.	c #B70606",
"}.	c #8A0909",
"|.	c #7D0A0A",
"1.	c #710C0C",
"2.	c #480F0F",
"3.	c #4D2727",
"4.	c #9B4C4C",
"5.	c #950909",
"6.	c #A40707",
"7.	c #750B0B",
"8.	c #4F0E0E",
"9.	c #421010",
"0.	c #695050",
"a.	c #890A0A",
"b.	c #960808",
"c.	c #760B0B",
"d.	c #6B0C0C",
"e.	c #3B1010",
"f.	c #7F2323",
"g.	c #8C0909",
"h.	c #610D0D",
"i.	c #4B0F0F",
"j.	c #3F1010",
"k.	c #462828",
"l.	c #6F0C0C",
"m.	c #680C0C",
"n.	c #5F0D0D",
"o.	c #4C0F0F",
"p.	c #411010",
"q.	c #361111",
"r.	c #936262",
"s.	c #670C0C",
"t.	c #5B0D0D",
"u.	c #530E0E",
"v.	c #371010",
"w.	c #746464",
"x.	c #8E6363",
"y.	c #5D0D0D",
"z.	c #590E0E",
"A.	c #470F0F",
"B.	c #612626",
"C.	c #510E0E",
"D.	c #460F0F",
"E.	c #3A1010",
"F.	c #452828",
"G.	c #734F4F",
"H.	c #542727",
"I.	c #421313",
"J.	c #3F1313",
"K.	c #4B2727",
"L.	c #675050",
"                                            ",
"                . + @ # $ %                 ",
"            & * * = - ; > , ' )             ",
"        ! ~ { ] ] { ~ ^ / > ( _ : <         ",
"      [ } | 1 2 2 1 | } ^ 3 4 5 6 7 8       ",
"      9 0 a b c c b a 0 9 d e f g h i       ",
"    j k l m n o o n m l p q r , s t u v     ",
"    ^ { w x y z A y B w { ^ C D E : F G     ",
"  H I J 1 K L M M L K 1 J ^ C N s : F G O   ",
"  P - Q R S c T T c S R Q - U V W X Y Z `   ",
"   ...* +.l @.m #.$.l +.* ..%.&.*.=.-.;.>.  ",
"  ,.'.).!.{ ~.{.{.~.{ !.).'.D ' ].^./.(._.  ",
"  :.4 C d <.[.} } [.<.d C 4 }.|.1.Y G 2.3.  ",
"  4.&.5.U 6.d - - d 6.U 5.&.W 7.^./.8.9.0.  ",
"    W a., b.> U U > b., a.W c.d.-.Z 2.e.    ",
"    f.*.E 5 g.( ( g.5 E *.: d.h.G i.j.k.    ",
"      l.7.6 |.g g |.6 7.l.m.n.G o.p.q.      ",
"      r.s.7 l.h h l.7 s.i t.u.i.p.v.w.      ",
"        x.y.-.h.h.-.y.z.Z (.A.j.q.w.        ",
"            B.;.u.C.8.i.D.p.E.F.            ",
"                G.H.I.J.K.L.                ",
"                                            "};
/* XPM */
static char * ball2_xpm[] = {
"22 22 142 2",
"  	c None",
". 	c #A7AF4A",
"+ 	c #A5A420",
"@ 	c #9C9B0B",
"# 	c #96950B",
"$ 	c #969521",
"% 	c #929C4B",
"& 	c #B3B11E",
"* 	c #B1AF06",
"= 	c #AFAD06",
"- 	c #AAA807",
"; 	c #A3A106",
"> 	c #999808",
", 	c #8F8D08",
"' 	c #83820A",
") 	c #838222",
"! 	c #75AF5C",
"~ 	c #B7B506",
"{ 	c #BCBA05",
"] 	c #C0BE05",
"^ 	c #AEAC05",
"/ 	c #A4A307",
"( 	c #8C8B09",
"_ 	c #7F7E0A",
": 	c #72710B",
"< 	c #688A5F",
"[ 	c #76AE5D",
"} 	c #B8B605",
"| 	c #C3C104",
"1 	c #CBC904",
"2 	c #CECC03",
"3 	c #A09E07",
"4 	c #949207",
"5 	c #87860A",
"6 	c #78770B",
"7 	c #6C6A0B",
"8 	c #678560",
"9 	c #B5B306",
"0 	c #C2C005",
"a 	c #CDCB04",
"b 	c #D8D603",
"c 	c #DDDB02",
"d 	c #A8A607",
"e 	c #7D7C0A",
"f 	c #6F6E0C",
"g 	c #61600C",
"h 	c #B0AE1F",
"i 	c #BAB805",
"j 	c #C9C704",
"k 	c #D6D403",
"l 	c #E3E102",
"m 	c #ECE901",
"n 	c #ABA906",
"o 	c #9D9C08",
"p 	c #81800A",
"q 	c #63620C",
"r 	c #636326",
"s 	c #D9D702",
"t 	c #E8E501",
"u 	c #F8F500",
"v 	c #DBD902",
"w 	c #9F9D08",
"x 	c #908F09",
"y 	c #64630D",
"z 	c #55550E",
"A 	c #A4AD48",
"B 	c #E6E301",
"C 	c #F4F100",
"D 	c #69724D",
"E 	c #A2A01F",
"F 	c #C5C304",
"G 	c #D2D003",
"H 	c #E5E302",
"I 	c #9B9A08",
"J 	c #8E8D09",
"K 	c #716F0A",
"L 	c #62610D",
"M 	c #53530E",
"N 	c #565627",
"O 	c #BEBC05",
"P 	c #D0CE03",
"Q 	c #D7D402",
"R 	c #979608",
"S 	c #8A8909",
"T 	c #7A790B",
"U 	c #6D6C0C",
"V 	c #5F5E0C",
"W 	c #51510E",
"X 	c #444311",
"Y 	c #91900C",
"Z 	c #B3B106",
"` 	c #C8C503",
" .	c #76750B",
"..	c #67660C",
"+.	c #5A5A0D",
"@.	c #4D4C0E",
"#.	c #404013",
"$.	c #908F21",
"%.	c #888709",
"&.	c #7C7A09",
"*.	c #706E0B",
"=.	c #47460E",
"-.	c #4C4C27",
";.	c #8C984B",
">.	c #949309",
",.	c #74730B",
"'.	c #4E4D0D",
").	c #414110",
"!.	c #5F664D",
"~.	c #959408",
"{.	c #69680C",
"].	c #3A390F",
"^.	c #7E7D23",
"/.	c #8B8908",
"(.	c #605F0D",
"_.	c #4B4A0E",
":.	c #3E3D0F",
"<.	c #454528",
"[.	c #6E6C0B",
"}.	c #5E5D0D",
"|.	c #403F0F",
"1.	c #353410",
"2.	c #668760",
"3.	c #65640C",
"4.	c #52510D",
"5.	c #36350F",
"6.	c #646E63",
"7.	c #658261",
"8.	c #5C5B0D",
"9.	c #58570D",
"0.	c #46460F",
"a.	c #605F25",
"b.	c #4F4F0E",
"c.	c #45440E",
"d.	c #393910",
"e.	c #444327",
"f.	c #68704D",
"g.	c #535226",
"h.	c #414012",
"i.	c #3E3E13",
"j.	c #4A4A27",
"k.	c #5E644D",
"                                            ",
"                . + @ # $ %                 ",
"            & * * = - ; > , ' )             ",
"        ! ~ { ] ] { ~ ^ / > ( _ : <         ",
"      [ } | 1 2 2 1 | } ^ 3 4 5 6 7 8       ",
"      9 0 a b c c b a 0 9 d > ( e f g       ",
"    h i j k l m m l k j i n o , p : q r     ",
"    ^ { 1 s t u u t v 1 { ^ w x p : y z     ",
"  A ^ { 1 b B C C B b 1 { ^ w x p : y z D   ",
"  E - } F G c H H c G F } - I J _ K L M N   ",
"  # / * O j P k Q G j O * / R S T U V W X   ",
"  Y o d Z { | ` ` | { Z d o x '  ...+.@.#.  ",
"  $.4 w d = 9 } } 9 = d w 4 %.&.*.L z =.-.  ",
"  ;.S >.I ; d - - d ; I >.S _ ,...+.'.).!.  ",
"    _ 5 , ~.> I I > ~., 5 _ ,.{.V M =.].    ",
"    ^.T p 5 /.( ( /.5 p T : {.(.z _.:.<.    ",
"      [.,.6 &.e e &.6 ,.[...}.z _.|.1.      ",
"      2.3.7 [.f f [.7 3.g +.4._.|.5.6.      ",
"        7.8.V (.(.V 8.9.M @.0.:.1.6.        ",
"            a.W 4.b.'._.c.|.d.e.            ",
"                f.g.h.i.j.k.                ",
"                                            "};
/* XPM */
static char * ball3_xpm[] = {
"22 22 139 2",
"  	c None",
". 	c #49AE4E",
"+ 	c #23A41F",
"@ 	c #0E9A0B",
"# 	c #0E950A",
"$ 	c #239520",
"% 	c #4A9B52",
"& 	c #25B11E",
"* 	c #0AAF06",
"= 	c #0DAE05",
"- 	c #0EA807",
"; 	c #0DA106",
"> 	c #0B9708",
", 	c #0E8D08",
"' 	c #0C810A",
") 	c #248122",
"! 	c #5BAE94",
"~ 	c #0AB506",
"{ 	c #09BA05",
"] 	c #09BF04",
"^ 	c #0DAC05",
"/ 	c #0AA306",
"( 	c #0C8B08",
"_ 	c #0C7D0A",
": 	c #0D710A",
"< 	c #5E897F",
"[ 	c #5CAD91",
"} 	c #09B605",
"| 	c #08C104",
"1 	c #08C904",
"2 	c #08CC03",
"3 	c #0E9E07",
"4 	c #0D9207",
"5 	c #0D850A",
"6 	c #0D770A",
"7 	c #0F6A0B",
"8 	c #5F847C",
"9 	c #0AB306",
"0 	c #09C005",
"a 	c #08CB04",
"b 	c #07D702",
"c 	c #07DB02",
"d 	c #0EA607",
"e 	c #0C7C09",
"f 	c #0E6E0B",
"g 	c #0E5F0C",
"h 	c #25AE1F",
"i 	c #09B805",
"j 	c #08C803",
"k 	c #08D403",
"l 	c #07E102",
"m 	c #0CEA01",
"n 	c #0DA906",
"o 	c #0B9B08",
"p 	c #0C7F0A",
"q 	c #0E610C",
"r 	c #276225",
"s 	c #0CE601",
"t 	c #0BF800",
"u 	c #07D902",
"v 	c #0F9D08",
"w 	c #0C8F08",
"x 	c #0E630C",
"y 	c #0F530E",
"z 	c #47AC4E",
"A 	c #0CE401",
"B 	c #0BF400",
"C 	c #4C7154",
"D 	c #25A11E",
"E 	c #08C304",
"F 	c #08D003",
"G 	c #07E302",
"H 	c #0B9908",
"I 	c #0C8C09",
"J 	c #0E6F0A",
"K 	c #0F520D",
"L 	c #275526",
"M 	c #09BC05",
"N 	c #08CE03",
"O 	c #0CD502",
"P 	c #0B9508",
"Q 	c #0C8809",
"R 	c #0D780B",
"S 	c #0E6C0B",
"T 	c #0F5D0C",
"U 	c #0F4F0E",
"V 	c #134310",
"W 	c #0F900B",
"X 	c #0AB106",
"Y 	c #0CC603",
"Z 	c #0D740B",
"` 	c #0E650C",
" .	c #0E590C",
"..	c #104C0D",
"+.	c #133F12",
"@.	c #238E21",
"#.	c #0B8609",
"$.	c #0E7A09",
"%.	c #0F6E0B",
"&.	c #10460D",
"*.	c #274B26",
"=.	c #4A9755",
"-.	c #0C9209",
";.	c #0D720B",
">.	c #0F4D0C",
",.	c #10400F",
"'.	c #4C6553",
").	c #0B9407",
"!.	c #0E670C",
"~.	c #10390E",
"{.	c #247D22",
"].	c #0E8908",
"^.	c #105F0C",
"/.	c #104A0D",
"(.	c #113D0E",
"_.	c #284427",
":.	c #0F6C0B",
"<.	c #105D0C",
"[.	c #113F0E",
"}.	c #11340F",
"|.	c #5F867F",
"1.	c #10510C",
"2.	c #10350E",
"3.	c #626D6C",
"4.	c #60817C",
"5.	c #105A0D",
"6.	c #10570C",
"7.	c #10450E",
"8.	c #275F24",
"9.	c #0F4E0D",
"0.	c #10440D",
"a.	c #10380F",
"b.	c #284326",
"c.	c #4C6F54",
"d.	c #275225",
"e.	c #144011",
"f.	c #133D12",
"g.	c #274926",
"h.	c #4C6351",
"                                            ",
"                . + @ # $ %                 ",
"            & * * = - ; > , ' )             ",
"        ! ~ { ] ] { ~ ^ / > ( _ : <         ",
"      [ } | 1 2 2 1 | } ^ 3 4 5 6 7 8       ",
"      9 0 a b c c b a 0 9 d > ( e f g       ",
"    h i j k l m m l k j i n o , p : q r     ",
"    ^ { 1 b s t t s u 1 { ^ v w p : x y     ",
"  z ^ { 1 b A B B A b 1 { ^ v w p : x y C   ",
"  D - } E F c G G c F E } - H I _ J q K L   ",
"  # / * M j N k O F j M * / P Q R S T U V   ",
"  W o d X { | Y Y | { X d o w ' Z `  ...+.  ",
"  @.4 v d = 9 } } 9 = d v 4 #.$.%.q y &.*.  ",
"  =.Q -.H ; d - - d ; H -.Q _ ;.`  .>.,.'.  ",
"    _ 5 , ).> H H > )., 5 _ ;.!.T K &.~.    ",
"    {.R p 5 ].( ( ].5 p R : !.^.y /.(._.    ",
"      :.;.6 $.e e $.6 ;.:.` <.y /.[.}.      ",
"      |.x 7 :.f f :.7 x g  .1./.[.2.3.      ",
"        4.5.T ^.^.T 5.6.K ..7.(.}.3.        ",
"            8.U 1.9.>./.0.[.a.b.            ",
"                c.d.e.f.g.h.                ",
"                                            "};
/* XPM */
static char * ball4_xpm[] = {
"22 22 137 2",
"  	c None",
". 	c #48A9AD",
"+ 	c #1FA29B",
"@ 	c #0A9994",
"# 	c #0A938B",
"$ 	c #20938D",
"% 	c #49939A",
"& 	c #1DB0A4",
"* 	c #05AEA4",
"= 	c #05AC9E",
"- 	c #07A69D",
"; 	c #069F96",
"> 	c #089590",
", 	c #088B84",
"' 	c #0A7F7B",
") 	c #21807C",
"! 	c #5A75AD",
"~ 	c #06B3AD",
"{ 	c #05B8B2",
"] 	c #04BDB2",
"^ 	c #05AA9D",
"/ 	c #06A198",
"( 	c #088982",
"_ 	c #097C77",
": 	c #0A6F69",
"< 	c #5D6888",
"[ 	c #5B7AAC",
"} 	c #05B4AE",
"| 	c #04BFB9",
"1 	c #03C8C1",
"2 	c #03CABF",
"3 	c #079C94",
"4 	c #079088",
"5 	c #0A837C",
"6 	c #0A756F",
"7 	c #0A6963",
"8 	c #5E6783",
"9 	c #06B1AB",
"0 	c #04BFB8",
"a 	c #04C9C2",
"b 	c #02D5CE",
"c 	c #02D9D2",
"d 	c #07A49B",
"e 	c #097A74",
"f 	c #0B6C67",
"g 	c #0C5D59",
"h 	c #1FACA4",
"i 	c #05B6B0",
"j 	c #03C6BB",
"k 	c #03D2C6",
"l 	c #02DFD7",
"m 	c #01E8D5",
"n 	c #06A79E",
"o 	c #089994",
"p 	c #0A7D79",
"q 	c #0C5F5C",
"r 	c #24615D",
"s 	c #01E4D1",
"t 	c #00F8E9",
"u 	c #02D7D0",
"v 	c #089B93",
"w 	c #088D85",
"x 	c #0C615E",
"y 	c #0D524F",
"z 	c #47A7AA",
"A 	c #01E2D0",
"B 	c #00F4E5",
"C 	c #4B6870",
"D 	c #1E9F95",
"E 	c #04C1BB",
"F 	c #03CEC2",
"G 	c #02E1D9",
"H 	c #089792",
"I 	c #088B86",
"J 	c #0A6D68",
"K 	c #0C514D",
"L 	c #255452",
"M 	c #05BAB4",
"N 	c #03CCC0",
"O 	c #02D3C2",
"P 	c #07948F",
"Q 	c #09867F",
"R 	c #0A7773",
"S 	c #0B6A65",
"T 	c #0C5B57",
"U 	c #0D4E4B",
"V 	c #0F423D",
"W 	c #0B8E87",
"X 	c #06AFA9",
"Y 	c #03C4B9",
"Z 	c #0B726F",
"` 	c #0C6360",
" .	c #0B5853",
"..	c #0C4B45",
"+.	c #113E3C",
"@.	c #218C89",
"#.	c #098480",
"$.	c #097872",
"%.	c #0C4540",
"&.	c #254A48",
"*.	c #498C96",
"=.	c #09908C",
"-.	c #0A716D",
";.	c #0B4C48",
">.	c #0E3F3D",
",.	c #4B5E64",
"'.	c #07928A",
").	c #0C6562",
"!.	c #0D3835",
"~.	c #227B78",
"{.	c #088780",
"].	c #0C5D57",
"^.	c #0C4944",
"/.	c #0D3C38",
"(.	c #264341",
"_.	c #0C5B55",
":.	c #0D3E3A",
"<.	c #0E3330",
"[.	c #5E6685",
"}.	c #0B504A",
"|.	c #0D3430",
"1.	c #61626C",
"2.	c #5F6580",
"3.	c #0C5954",
"4.	c #0B564F",
"5.	c #0D4440",
"6.	c #235E59",
"7.	c #0C4D49",
"8.	c #0C433E",
"9.	c #0E3734",
"0.	c #25423F",
"a.	c #4B676E",
"b.	c #24514E",
"c.	c #103F3B",
"d.	c #113C3A",
"e.	c #254846",
"f.	c #4B5D62",
"                                            ",
"                . + @ # $ %                 ",
"            & * * = - ; > , ' )             ",
"        ! ~ { ] ] { ~ ^ / > ( _ : <         ",
"      [ } | 1 2 2 1 | } ^ 3 4 5 6 7 8       ",
"      9 0 a b c c b a 0 9 d > ( e f g       ",
"    h i j k l m m l k j i n o , p : q r     ",
"    ^ { 1 b s t t s u 1 { ^ v w p : x y     ",
"  z ^ { 1 b A B B A b 1 { ^ v w p : x y C   ",
"  D - } E F c G G c F E } - H I _ J q K L   ",
"  # / * M j N k O F j M * / P Q R S T U V   ",
"  W o d X { | Y Y | { X d o w ' Z `  ...+.  ",
"  @.4 v d = 9 } } 9 = d v 4 #.$.f q y %.&.  ",
"  *.Q =.H ; d - - d ; H =.Q _ -.`  .;.>.,.  ",
"    _ 5 , '.> H H > '., 5 _ -.).T K %.!.    ",
"    ~.R p 5 {.( ( {.5 p R : ).].y ^./.(.    ",
"      S -.6 $.e e $.6 -.S ` _.y ^.:.<.      ",
"      [.x 7 S f f S 7 x g  .}.^.:.|.1.      ",
"        2.3.T ].].T 3.4.K ..5./.<.1.        ",
"            6.U }.7.;.^.8.:.9.0.            ",
"                a.b.c.d.e.f.                ",
"                                            "};
/* XPM */
static char * ball5_xpm[] = {
"22 22 135 2",
"  	c None",
". 	c #4A47AC",
"+ 	c #1E28A1",
"@ 	c #0A1097",
"# 	c #0A1391",
"$ 	c #202891",
"% 	c #4E4998",
"& 	c #1D2AAE",
"* 	c #0515AC",
"= 	c #0518AA",
"- 	c #0712A4",
"; 	c #06109D",
"> 	c #071194",
", 	c #081189",
"' 	c #0A0F7D",
") 	c #20277F",
"! 	c #9059AC",
"~ 	c #060EB1",
"{ 	c #050DB6",
"] 	c #0415BB",
"^ 	c #0514A8",
"/ 	c #06119F",
"( 	c #081187",
"_ 	c #09117A",
": 	c #0A136D",
"< 	c #7B5C87",
"[ 	c #8A5AAB",
"} 	c #050DB2",
"| 	c #040CBD",
"1 	c #0310C6",
"2 	c #0311C8",
"3 	c #06119B",
"4 	c #07108E",
"5 	c #0A1281",
"6 	c #0A1173",
"7 	c #0A1267",
"8 	c #785D82",
"9 	c #060EAF",
"0 	c #0411BD",
"a 	c #020BD3",
"b 	c #020CD7",
"c 	c #0612A3",
"d 	c #091178",
"e 	c #0B116A",
"f 	c #0C115B",
"g 	c #1E28AB",
"h 	c #050DB4",
"i 	c #0310C4",
"j 	c #0311D0",
"k 	c #0211DD",
"l 	c #0116E6",
"m 	c #0611A5",
"n 	c #080E97",
"o 	c #090F7C",
"p 	c #0C115D",
"q 	c #232960",
"r 	c #011BE2",
"s 	c #0017F8",
"t 	c #020CD5",
"u 	c #081299",
"v 	c #08148B",
"w 	c #0C105F",
"x 	c #0C1151",
"y 	c #4747A8",
"z 	c #0116E0",
"A 	c #0016F4",
"B 	c #514A6F",
"C 	c #1D299E",
"D 	c #040DBF",
"E 	c #0316CC",
"F 	c #0211DF",
"G 	c #080E95",
"H 	c #09106C",
"I 	c #0B1050",
"J 	c #242753",
"K 	c #050DB8",
"L 	c #0316CA",
"M 	c #0215D1",
"N 	c #071192",
"O 	c #091184",
"P 	c #0A1175",
"Q 	c #0A1169",
"R 	c #0B115A",
"S 	c #0C114D",
"T 	c #0E1441",
"U 	c #0B148C",
"V 	c #0511AE",
"W 	c #0310C2",
"X 	c #0A0F71",
"Y 	c #0C1061",
"Z 	c #0A1257",
"` 	c #0B134A",
" .	c #10133D",
"..	c #21268A",
"+.	c #090E82",
"@.	c #091076",
"#.	c #0B1244",
"$.	c #242749",
"%.	c #514895",
"&.	c #080F8F",
"*.	c #0A116F",
"=.	c #0A104B",
"-.	c #0D113E",
";.	c #4F4A63",
">.	c #071090",
",.	c #0C1063",
"'.	c #0C1037",
").	c #21267A",
"!.	c #081085",
"~.	c #0C135B",
"{.	c #0B1148",
"].	c #0C123B",
"^.	c #252842",
"/.	c #0B135A",
"(.	c #0C113D",
"_.	c #0D1132",
":.	c #7B5D84",
"<.	c #0A124F",
"[.	c #0C1133",
"}.	c #6A606B",
"|.	c #785E7F",
"1.	c #0B1358",
"2.	c #0A1355",
"3.	c #0C1143",
"4.	c #22295D",
"5.	c #0B114C",
"6.	c #0B1242",
"7.	c #0D1136",
"8.	c #242841",
"9.	c #514A6D",
"0.	c #232750",
"a.	c #0F153E",
"b.	c #10133B",
"c.	c #242747",
"d.	c #4F4A61",
"                                            ",
"                . + @ # $ %                 ",
"            & * * = - ; > , ' )             ",
"        ! ~ { ] ] { ~ ^ / > ( _ : <         ",
"      [ } | 1 2 2 1 | } ^ 3 4 5 6 7 8       ",
"      9 0 2 a b b a 2 0 9 c > ( d e f       ",
"    g h i j k l l k j i h m n , o : p q     ",
"    ^ { 1 a r s s r t 1 { ^ u v o : w x     ",
"  y ^ { 1 a z A A z a 1 { ^ u v o : w x B   ",
"  C - } D E b F F b E D } - G , _ H p I J   ",
"  # / * K i L j M E i K * / N O P Q R S T   ",
"  U n c V { | W W | { V c n v ' X Y Z `  .  ",
"  ..4 u c = 9 } } 9 = c u 4 +.@.e p x #.$.  ",
"  %.O &.G ; c - - c ; G &.O _ *.Y Z =.-.;.  ",
"    _ 5 , >.> G G > >., 5 _ *.,.R I #.'.    ",
"    ).P o 5 !.( ( !.5 o P : ,.~.x {.].^.    ",
"      Q *.6 @.d d @.6 *.Q Y /.x {.(._.      ",
"      :.w 7 Q e e Q 7 w f Z <.{.(.[.}.      ",
"        |.1.R ~.~.R 1.2.I ` 3.]._.}.        ",
"            4.S <.5.=.{.6.(.7.8.            ",
"                9.0.a.b.c.d.                ",
"                                            "};
/* XPM */
static char * ball6_xpm[] = {
"22 22 135 2",
"  	c None",
". 	c #AA47A9",
"+ 	c #921E9F",
"@ 	c #8D0A95",
"# 	c #840990",
"$ 	c #84208F",
"% 	c #974894",
"& 	c #9D1CAD",
"* 	c #9505AA",
"= 	c #9305A8",
"- 	c #9606A3",
"; 	c #8F069B",
"> 	c #830792",
", 	c #7D0887",
"' 	c #75097C",
") 	c #741F7E",
"! 	c #AB5875",
"~ 	c #A506AF",
"{ 	c #AA05B4",
"] 	c #A604B9",
"^ 	c #9505A6",
"/ 	c #8D069D",
"( 	c #780885",
"_ 	c #6D0978",
": 	c #61096C",
"< 	c #865B68",
"[ 	c #AA597B",
"} 	c #A604B1",
"| 	c #B104BB",
"1 	c #B403C4",
"2 	c #B203C6",
"3 	c #8A0699",
"4 	c #81068D",
"5 	c #760A7F",
"6 	c #690972",
"7 	c #5C0A65",
"8 	c #815C67",
"9 	c #A005AE",
"0 	c #AC04BB",
"a 	c #C502D1",
"b 	c #C902D5",
"c 	c #9106A1",
"d 	c #6B0976",
"e 	c #610A69",
"f 	c #530B5A",
"g 	c #9B1EA9",
"h 	c #A805B2",
"i 	c #B303C2",
"j 	c #BD03CE",
"k 	c #C902DB",
"l 	c #CC01E4",
"m 	c #9605A4",
"n 	c #8D0895",
"o 	c #71097A",
"p 	c #550C5B",
"q 	c #57225F",
"r 	c #C301E0",
"s 	c #DD00F8",
"t 	c #C202D3",
"u 	c #8C0897",
"v 	c #7C0889",
"w 	c #570C5D",
"x 	c #480B50",
"y 	c #A546A7",
"z 	c #C201DE",
"A 	c #DA00F4",
"B 	c #6E4967",
"C 	c #8F1D9C",
"D 	c #AE04BD",
"E 	c #B003CA",
"F 	c #CB02DD",
"G 	c #8B0794",
"H 	c #60096A",
"I 	c #470A4F",
"J 	c #4E2352",
"K 	c #AC05B6",
"L 	c #AF03C8",
"M 	c #BA02CF",
"N 	c #820790",
"O 	c #780982",
"P 	c #6B0A73",
"Q 	c #5E0A67",
"R 	c #500A59",
"S 	c #450B4C",
"T 	c #390D40",
"U 	c #800B8A",
"V 	c #9B05AC",
"W 	c #B103C0",
"X 	c #670A6F",
"Y 	c #5A0C5F",
"Z 	c #4C0956",
"` 	c #3F0A49",
" .	c #380F3C",
"..	c #802089",
"+.	c #790980",
"@.	c #6B0974",
"#.	c #3A0B42",
"$.	c #442348",
"%.	c #93488D",
"&.	c #82088D",
"*.	c #650A6D",
"=.	c #43094A",
"-.	c #370C3D",
";.	c #62495D",
">.	c #83078E",
",.	c #5C0C61",
"'.	c #310B36",
").	c #712079",
"!.	c #790784",
"~.	c #510B5A",
"{.	c #3F0A47",
"].	c #330B3A",
"^.	c #3D2441",
"/.	c #4E0A59",
"(.	c #350B3C",
"_.	c #2C0C31",
":.	c #835C66",
"<.	c #450A4D",
"[.	c #2C0B32",
"}.	c #6A5F61",
"|.	c #7E5D65",
"1.	c #4D0A57",
"2.	c #480954",
"3.	c #3C0B42",
"4.	c #53215C",
"5.	c #440A4B",
"6.	c #380A41",
"7.	c #2F0C35",
"8.	c #3B2340",
"9.	c #6C4966",
"0.	c #4A224F",
"a.	c #360E3D",
"b.	c #360F3A",
"c.	c #422346",
"d.	c #60495B",
"                                            ",
"                . + @ # $ %                 ",
"            & * * = - ; > , ' )             ",
"        ! ~ { ] ] { ~ ^ / > ( _ : <         ",
"      [ } | 1 2 2 1 | } ^ 3 4 5 6 7 8       ",
"      9 0 2 a b b a 2 0 9 c > ( d e f       ",
"    g h i j k l l k j i h m n , o : p q     ",
"    ^ { 1 a r s s r t 1 { ^ u v o : w x     ",
"  y ^ { 1 a z A A z a 1 { ^ u v o : w x B   ",
"  C - } D E b F F b E D } - G , _ H p I J   ",
"  # / * K i L j M E i K * / N O P Q R S T   ",
"  U n c V { | W W | { V c n v ' X Y Z `  .  ",
"  ..4 u c = 9 } } 9 = c u 4 +.@.e p x #.$.  ",
"  %.O &.G ; c - - c ; G &.O _ *.Y Z =.-.;.  ",
"    _ 5 , >.> G G > >., 5 _ *.,.R I #.'.    ",
"    ).P o 5 !.( ( !.5 o P : ,.~.x {.].^.    ",
"      Q *.6 @.d d @.6 *.Q Y /.x {.(._.      ",
"      :.w 7 Q e e Q 7 w f Z <.{.(.[.}.      ",
"        |.1.R ~.~.R 1.2.I ` 3.]._.}.        ",
"            4.S <.5.=.{.6.(.7.8.            ",
"                9.0.a.b.c.d.                ",
"                                            "};

#endif
