using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2.ClassCS
{
    class Player
    {
        public string strName;
        public int nHP;
        public int nDemage;
        public Player(string name, int hp, int dem)
        {
            strName = name;
            nHP = hp;
            nDemage = dem;
        }
        public void Attack(Player target)
        {
            target.nHP = target.nHP - this.nDemage;
        }
        public bool Death()
        {
            if (nHP > 0)
                return false;
            else
                return true;
        }
        public void Display(string msg)
        {
            Console.WriteLine("##### "+msg+" #######");
            Console.WriteLine("Name:" + strName);
            Console.WriteLine("Demage:" + nDemage);
            Console.WriteLine("HP:" + nHP);
            Console.WriteLine("###################");
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            RPGMain();
        }

        static void RPGMain()
        {
            Player cPlayer = new Player("player", 100, 10);

            List<Player> listMonsters = new List<Player>();
            listMonsters.Add(new Player("slime", 100, 10));
            listMonsters.Add(new Player("skeleton", 100, 10));
            listMonsters.Add(new Player("zombie", 100, 10));
            listMonsters.Add(new Player("dragon", 100, 10));

            while (true)
            {
                for (int i = 0; i < listMonsters.Count; i++)
                {
                    Console.WriteLine("[" + i + "]:" + listMonsters[i].strName);
                }
                int nIdx = int.Parse(Console.ReadLine());
                Console.WriteLine("Idx:" + nIdx);

                if (nIdx >= 0 && nIdx < listMonsters.Count) // 0 < idx < conut
                {
                    Player cMonster = listMonsters[nIdx];

                    Battle(cPlayer, cMonster);
                }
                else
                {
                    Console.WriteLine("Exit");
                    break;
                }
            }
        }

        static void Battle(Player player, Player monster)
        {
            while(true)
            {
                if (player.Death() == false)
                {
                    player.Attack(monster);
                    monster.Display("Player Attack!");
                }
                else
                {
                    Console.WriteLine(monster.strName + " Win!");
                    break;
                }
                if (monster.Death() == false)
                {
                    monster.Attack(player);
                    player.Display("Monster Attack!");
                }
                else
                {
                    Console.WriteLine(player.strName + " Win!");
                    break;
                }
            }
        }
    }
}
