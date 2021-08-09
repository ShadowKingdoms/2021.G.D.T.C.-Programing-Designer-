using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Item : MonoBehaviour
{
    public int Score;
    public enum ITEM_KIND { SUPER_MODE, RECOVERY, LASER, BULLET, GRENADE  }
    public ITEM_KIND item_kind;
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    private void OnTriggerEnter2D(Collider2D collision)
    {
        if(collision.gameObject.tag == "Player")
        {
            Dynamic dynamic = collision.gameObject.GetComponent<Dynamic>();
            switch(item_kind)
            {
                case ITEM_KIND.SUPER_MODE:
                    SuperMode superMode = collision.gameObject.GetComponent<SuperMode>();
                    superMode.OnMode();
                    break;
                case ITEM_KIND.RECOVERY:
                    Player player = collision.gameObject.GetComponent<Player>();
                    if(player.Recovery() == false)
                    {
                        dynamic.Score += Score;
                    }
                    break;
                case ITEM_KIND.LASER:
                    //Dynamic dynamic = collision.gameObject.GetComponent<Dynamic>();
                    dynamic.gun.eGunState = Gun.E_GUN_STATE.LASER_GUN;
                    break;
                case ITEM_KIND.BULLET:
                    //Dynamic dynamic = collision.gameObject.GetComponent<Dynamic>();
                    dynamic.gun.eGunState = Gun.E_GUN_STATE.BULLET_GUN;
                    break;
                case ITEM_KIND.GRENADE:

                    break;
            }


            Destroy(this.gameObject);
        }
    }
}
