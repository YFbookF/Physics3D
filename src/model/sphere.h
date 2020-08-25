#pragma once
#include "object.h"

class Sphere : public Object {
public:
    virtual ~Sphere() = default;

    Sphere(double radius);

    const double& GetRadius() const;

    virtual Vec3 GetSupportingPoint(Vec3 direction) const override;

protected:
    virtual void TransformationUpdated() override;

    virtual void RecalculateInertia() override;

    double radius;
};