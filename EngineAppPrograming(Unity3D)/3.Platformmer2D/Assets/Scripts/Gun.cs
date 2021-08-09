using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Gun : MonoBehaviour
{
    public GameObject objBullet;
    public Transform trMozzle;
    public float ShotPower;
    public int nBulletCount = 5;

    public enum E_GUN_STATE {NONE, BULLET_GUN, LASER_GUN }
    public E_GUN_STATE eGunState;

    public void Shot(Vector3 dir, Player player)
    {
        switch(eGunState)
        {
            case E_GUN_STATE.BULLET_GUN:
                BulletGun(dir, player);
                break;
            case E_GUN_STATE.LASER_GUN:
                LaserGun(dir, player);
                break;
        }
    }
    public void BulletGun(Vector3 dir, Player player)
    {
        if (nBulletCount > 0)
        {
            GameObject objCopyBullet = Instantiate(objBullet);
            objCopyBullet.transform.position = trMozzle.position;
            Rigidbody2D rigidbody = objCopyBullet.GetComponent<Rigidbody2D>();
            rigidbody.AddForce(dir * ShotPower);
            Bullet bullet = objCopyBullet.GetComponent<Bullet>();
            bullet.master = player;
            bullet.gun = this;
            nBulletCount--;
        }
    }

    public void LaserGun(Vector3 dir, Player player)
    {
        if (nBulletCount > 0)
        {
            float fDist = 999999;
            Vector3 vPos = transform.position;
            int nLayer = 1 << LayerMask.NameToLayer("Monster");
            RaycastHit2D raycastHit = Physics2D.Raycast(vPos, dir, fDist, nLayer);
            Vector3 vEndDist = vPos + dir * fDist;
            if(raycastHit.collider)
            {
                Debug.DrawLine(vPos, raycastHit.point);
            }
            else
                Debug.DrawLine(vPos, vEndDist);
        }
    }

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
       
    }
}
